from ptrlib import *

fs = [
    "sample.exe",
    "sample.exe",
]

#sock = Socket("localhost", 10000)
sock = Socket("nc 141.164.48.191 10000")

sock.sendlineafter(": ", str(len(fs)))
for f in fs:
    buf = open(f, "rb").read()
    assert len(buf) < 10000
    sock.sendlineafter(": ", str(len(buf)))
    sock.sendafter(": ", buf)

sock.interactive()
