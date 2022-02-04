#include <stdio.h>
#include <stdlib.h>

void FUN_004008dc(void) {
    long lVar1;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    setvbuf(stdin, (char *)0x0, 2, 0);
    setvbuf(stderr, (char *)0x0, 2, 0);
    alarm(0x1e);
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

void FUN_00400950(void) {
    long lVar1;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    system("cat banner.txt");
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

void FUN_00400bce(void) {
    long in_FS_OFFSET;
    int local_14;
    unsigned long local_10;

    local_10 = *(unsigned long *)(in_FS_OFFSET + 0x28);
    FUN_004008dc();
    FUN_00400950();
    do {
        while (1) {
            __isoc99_scanf("%d", &local_14);
            getchar();
            if (local_14 != 2)
                break;
            freeSt();
        }
        if (local_14 == 3) {
            FUN_00400b42();
        }
        else {
            if (local_14 == 1) {
                alloc();
            }
        }
    } while (1);
}

unsigned long freeSt(void) {
    unsigned long uVar1;
    long in_FS_OFFSET;
    int local_14;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    __isoc99_scanf("%d", &local_14);
    getchar();
    if ((local_14 < 0) || (9 < local_14)) {
        uVar1 = 0xffffffff;
    }
    else {
        free(*(void **)(&DAT_006020c0 + (long)local_14 * 8));
        uVar1 = 0;
    }
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return uVar1;
}

// 0x400876
unsigned long readSt(void *param_1, long param_2) {
    long lVar1;
    unsigned long uVar2;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    uVar2 = read(0, param_1, param_2 - 1);
    *(char*)((long)param_1 + param_2 + -1) = 0;
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return uVar2 & 0xffffffff;
}

unsigned long FUN_00400b42(void) {
    unsigned long uVar1;
    long in_FS_OFFSET;
    int local_14;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    __isoc99_scanf("%d", &local_14);
    getchar();
    if ((local_14 < 0) || (9 < local_14)) {
        uVar1 = 0xffffffff;
    }
    else {
        readSt(*(unsigned long *)(&DAT_006020c0 + (long)local_14 * 8), 8);
        readSt(&DAT_00602120, 0x30);
        uVar1 = 0;
    }
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return uVar1;
}

// 0x400988
unsigned long alloc(void) {
    unsigned long uVar1;
    long in_FS_OFFSET;
    long local_28;
    unsigned long local_20;
    void *local_18;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    __isoc99_scanf("%lu", &local_28);
    getchar();
    if (local_28 == 1) {
        local_18 = malloc(0x10);
    }
    else {
        if (local_28 == 2) {
            local_18 = malloc(0x80);
        }
        else {
            if (local_28 == 3) {
                local_18 = malloc(0xa00000);
            }
            else {
                if (local_28 == 0x3419) {
                    if (DAT_00602154 == 1) {
                        uVar1 = 0xffffffff;
                        goto LAB_00400ab4;
                    }
                    local_18 = malloc(0xffffffffffffff70);
                    DAT_00602154 = 1;
                }
            }
        }
    }

    if (local_18 == (void *)0x0) {
        uVar1 = 0xffffffff;
    }
    else {
        readSt(local_18, 8);
        for (local_20 = 0; (local_20 < 10 && (*(long *)(&DAT_006020c0 + local_20 * 8) != 0));
             local_20 = local_20 + 1) 
        {
        }

        if (local_20 == 10) {
            exit(0);
        }
        *(void **)(&DAT_006020c0 + local_20 * 8) = local_18;
        uVar1 = 0;
    }
LAB_00400ab4:
    if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
        return uVar1;
    }
    __stack_chk_fail();
}