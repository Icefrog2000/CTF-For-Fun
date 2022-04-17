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

while True:
    sock = Process("./HNoteFixed")

    L = 8
    l = []
    for cnt in range(0, 40):
        choice = random_int(0, 4)
        if choice == 0 or choice == 3 or choice == 4:
            s = random_int(0, 2)
            if s != 2 and len(l) > 0:
                name, data = random.choice(l)
                if s == 0:
                    print(f"add({name}, {data})")
                    add(name, data)
                else:
                    data = random_bytes(1, L)
                    print(f"add({name}, {data})")
                    add(name, data)
                    l.append((name, data))
            else:
                name = random_bytes(1, L)
                data = random_bytes(1, L)
                print(f"add({name}, {data})")
                add(name, data)
                l.append((name, data))
        elif choice == 1 and len(l) > 0:
            name, _ = random.choice(l)
            print(f"delete({name})")
            delete(name)
        elif choice == 2 and len(l) > 0:
            name, _ = random.choice(l)
            data = random_bytes(1, L)
            print(f"edit({name}, {data})")

    sock.close()
