ax  = 0
bx  = 1
cx  = 2
dx  = 3
si  = 4
di  = 5
rbp = 6
rsp = 7
pc  = 11

def to_16(b):
    return b.to_bytes(2, "little")

def val8(val):
    kind = 4
    size = 1
    return bytes([(kind << 4) | size]) + val.to_bytes(1, "little")

def val16(val):
    kind = 4
    size = 2
    return bytes([(kind << 4) | size]) + val.to_bytes(2, "little")

def val32(val):
    kind = 4
    size = 4
    return bytes([(kind << 4) | size]) + val.to_bytes(4, "little")

def val64(val):
    kind = 4
    size = 8
    return bytes([(kind << 4) | size]) + val.to_bytes(8, "little")

def stack_top():
    return bytes([0x10])

# def mem(addrsize, addr, size):
#     kind = 2
#     return bytes([(kind << 4) | addrsize])  + size.to_bytes(1, "little") + addr.to_bytes(addrsize, "little")

def mem8(addr):
    kind = 2
    size = 1
    addrsize = 1 if addr == 0 else (addr.bit_length() + 7) // 8
    return bytes([(kind << 4) | addrsize]) + addr.to_bytes(addrsize, "little") + size.to_bytes(1, "little")

def mem16(addr):
    kind = 2
    size = 2
    addrsize = 1 if addr == 0 else (addr.bit_length() + 7) // 8
    return bytes([(kind << 4) | addrsize]) + addr.to_bytes(addrsize, "little") + size.to_bytes(1, "little")

def mem32(addr):
    kind = 2
    size = 4
    addrsize = 1 if addr == 0 else (addr.bit_length() + 7) // 8
    return bytes([(kind << 4) | addrsize]) + addr.to_bytes(addrsize, "little") + size.to_bytes(1, "little")

def mem64(addr):
    kind = 2
    size = 8
    addrsize = 1 if addr == 0 else (addr.bit_length() + 7) // 8
    return bytes([(kind << 4) | addrsize]) + addr.to_bytes(addrsize, "little") + size.to_bytes(1, "little")

def reg(r):
    kind = 3
    return bytes([(kind << 4) | r])

def mov(dst, src):
    return bytes([0]) + to_16(dst[0]) + to_16(src[0]) + src[1:] + dst[1:]

def push(src):
    return bytes([1]) + to_16(src[0]) + src[1:]

def pop(dst):
    return bytes([2]) + to_16(dst[0]) + dst[1:]

def xchg(dst, src):
    return bytes([3]) + to_16(dst[0]) + to_16(src[0]) + src[1:] + dst[1:]

def add(dst, src1, src2):
    return bytes([4]) + to_16(dst[0]) + to_16(src1[0]) + to_16(src2[0]) + src1[1:] + src2[1:] + dst[1:]

def sub(dst, src1, src2):
    return bytes([5]) + to_16(dst[0]) + to_16(src1[0]) + to_16(src2[0]) + src1[1:] + src2[1:] + dst[1:]

def mul(dst, src1, src2):
    return bytes([6]) + to_16(dst[0]) + to_16(src1[0]) + to_16(src2[0]) + src1[1:] + src2[1:] + dst[1:]

def div(dst, src1, src2):
    return bytes([7]) + to_16(dst[0]) + to_16(src1[0]) + to_16(src2[0]) + src1[1:] + src2[1:] + dst[1:]

def debug_stack():
    return bytes([8]) + (0x10).to_bytes(2, "little")

def debug_mem8(addr):
    size = 1
    return bytes([8]) + (0x20 | size).to_bytes(2, "little") + addr.to_bytes(size, "little")

def debug_mem16(addr):
    size = 2
    return bytes([8]) + (0x20 | size).to_bytes(2, "little") + addr.to_bytes(size, "little")

def debug_mem32(addr):
    size = 4
    return bytes([8]) + (0x20 | size).to_bytes(2, "little") + addr.to_bytes(size, "little")

def debug_mem64(addr):
    size = 8
    return bytes([8]) + (0x20 | size).to_bytes(2, "little") + addr.to_bytes(size, "little")

def debug_regs():
    return bytes([8]) + (0x30).to_bytes(2, "little")
