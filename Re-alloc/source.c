#include <stdio.h>

char* heap[2]; // 0x104050

void handler(void) {
    puts("Timeout");
    _exit(1);
}

void init_proc(void) {
    setvbuf(stdin, (char *)0x0, 2, 0);
    setvbuf(stdout, (char *)0x0, 2, 0);
    setvbuf(stderr, (char *)0x0, 2, 0);
    signal(0xe, handler);
    alarm(0x3c);
    return;
}

long long read_long(void) {
    long long lVar1;
    long in_FS_OFFSET;
    char local_28[24];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    __read_chk(0, local_28, 0x10, 0x11);
    lVar1 = atoll(local_28);
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return lVar1;
}

void menu(void) {
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    puts(&DAT_00102070);
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    puts("$   1. Alloc               $");
    puts("$   2. Realloc             $");
    puts("$   3. Free                $");
    puts("$   4. Exit                $");
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    printf("Your choice: ");
    return;
}

void main(void) {
    long in_FS_OFFSET;
    int local_14;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    local_14 = 0;
    init_proc();
    do {
        while (1) {
            while (1) {
                menu();
                scanf("%d", &local_14);
                if (local_14 != 2)
                    break;
                reallocate();
            }
            if (2 < local_14)
                break;
            if (local_14 == 1) {
                allocate();
            } else {
            LAB_00101790:
                puts("Invalid Choice");
            }
        }
        if (local_14 != 3) {
            if (local_14 == 4) {
                _exit(0);
            }
            goto LAB_00101790;
        }
        rfree();
    } while (1);
}

long read_input(long param_1, int param_2) {
    int iVar1;
    long lVar2;

    iVar1 = __read_chk(0, param_1, param_2, param_2);
    lVar2 = (long)iVar1;
    if (lVar2 == 0) {
        puts("read error");
        _exit(1);
    }
    if (*(char *)(param_1 + lVar2 + -1) == '\n') {
        *(char *)(param_1 + lVar2 + -1) = 0;
    }
    return lVar2;
}

void allocate() {
    unsigned long uVar1;
    unsigned long __size;
    void *pvVar2;
    long lVar3;

    printf("Index:");
    uVar1 = read_long();
    if ((uVar1 < 2) && (heap[uVar1] == 0)) {
        printf("Size:");
        __size = read_long();
        if (__size < 0x79) {
            pvVar2 = malloc(__size);
            if (pvVar2 == (void *)0x0) {
                puts("alloc error");
            } else {
                heap[uVar1] = pvVar2;
                printf("Data:");
                lVar3 = read_input(heap[uVar1], __size & 0xffffffff);
                *(char *)(lVar3 + heap[uVar1]) = 0;
            }
        } else {
            puts("Too large!");
        }
    } else {
        puts("Invalid !");
    }
    return;
}

void reallocate(void) {
    unsigned long uVar1;
    unsigned long __size;
    void *pvVar2;

    printf("Index:");
    uVar1 = read_long();
    if ((uVar1 < 2) && (heap[uVar1] != 0)) {
        printf("Size:");
        __size = read_long();
        if (__size < 0x79) {
            pvVar2 = realloc(heap[uVar1], __size);
            if (pvVar2 == (void *)0x0) {
                puts("alloc error");
            } else {
                heap[uVar1] = pvVar2;
                printf("Data:");
                read_input(heap[uVar1], __size & 0xffffffff);
            }
        } else {
            puts("Too large!");
        }
    } else {
        puts("Invalid !");
    }
    return;
}

void rfree(void) {
    unsigned long uVar1;

    printf("Index:");
    uVar1 = read_long();
    if (uVar1 < 2) {
        realloc(heap[uVar1], 0);
        heap[uVar1] = 0;
    } else {
        puts("Invalid !");
    }
    return;
}
