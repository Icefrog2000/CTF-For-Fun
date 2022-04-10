#include <stdio.h>

// 0x40122b
void init(long *param_1) {
    setvbuf(stdin, (char *)0x0, 1, 0);
    setvbuf(stdout, (char *)0x0, 2, 0);
    memset(param_1, 0, 0x108);
    *param_1 = (long)param_1 + 9;
    *(undefined *)(param_1 + 1) = 0xff;
    DAT_0040508c = 0;
    return;
}

// 0x401216
void menu(void) {
    puts(&DAT_00402008);
    return;
}

// 0x4012b1
int read_int(void) {
    ssize_t sVar1;
    long in_FS_OFFSET;
    int local_3c;
    undefined8 local_38;
    undefined8 local_30;
    undefined8 local_28;
    undefined8 local_20;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    local_38 = 0;
    local_30 = 0;
    local_28 = 0;
    local_20 = 0;
    local_3c = -1;
    sVar1 = read(0, &local_38, 0x10);
    if (0 < sVar1) {
        local_3c = atoi((char *)&local_38);
    }
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        /* WARNING: Subroutine does not return */
        __stack_chk_fail();
    }
    return local_3c;
}

// 0x40143b
void choose(void) {
    puts(&DAT_00402a10);
    write(1, &DAT_00402cd0, 2);
    read_int();
    return;
}

// 0x40146f
undefined8 main(void) {
    int iVar1;
    long in_FS_OFFSET;
    undefined local_118[264];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    init(local_118);
    menu();
LAB_0040154a:
    while (1) {
        if (DAT_0040508c != 0) {
            if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
                return 0;
            }
            /* WARNING: Subroutine does not return */
            __stack_chk_fail();
        }
        iVar1 = choose();
        if (iVar1 != 4)
            break;
        DAT_0040508c = 1;
    }
    if (iVar1 < 5) {
        if (iVar1 == 3) {
            alloc(local_118);
            goto LAB_0040154a;
        }
        if (3 < iVar1)
            goto LAB_0040153f;
        if (iVar1 == 1) {
            read_st(local_118);
            goto LAB_0040154a;
        }
        if (iVar1 == 2)
        {
            leak(local_118);
            goto LAB_0040154a;
        }
    }
LAB_0040153f:
    puts("que?");
    goto LAB_0040154a;
}

// 0x4013a2
void alloc(void **param_1) {
    int iVar1;
    ssize_t sVar2;
    void *pvVar3;

    sVar2 = write(1, "size: ", 6);
    if (sVar2 != 0) {
        iVar1 = read_int();
        if (iVar1 < 0x81) {
            pvVar3 = malloc((long)(iVar1 + 1));
            if (pvVar3 == (void *)0x0) {
                puts("\x1b[31mfail:\x1b[0m can\'t allocate memory...");
            } else {
                *param_1 = pvVar3;
                *(int *)(param_1 + 1) = iVar1;
            }
        } else {
            puts("\x1b[31mfail:\x1b[0m c\'mon bruh...");
        }
    }
    return;
}

// 0x401336
void read_st(void **param_1) {
    read(0, *param_1, (unsigned long) * (unsigned int *)(param_1 + 1));
    return;
}

// 0x401368
void leak(char *param_1) {
    ssize_t sVar1;

    sVar1 = write(1, "leak: ", 6);
    if (sVar1 != 0) {
        puts(param_1);
    }
    return;
}