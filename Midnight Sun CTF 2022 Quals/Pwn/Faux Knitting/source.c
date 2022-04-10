#include <stdio.h>

void FUN_001012c9(void) {
    puts(&DAT_00102008);
    return;
}

undefined[16] FUN_001012e3(void) {
    int *piVar1;
    int iVar2;
    time_t tVar3;
    long lVar4;
    undefined8 extraout_RDX;
    long in_FS_OFFSET;
    int local_68;
    void *local_60;
    int *local_58;
    void *local_50;
    int *local_48;
    long local_40;

    local_40 = *(long *)(in_FS_OFFSET + 0x28);
    local_60 = (void *)0x0;
    local_50 = (void *)0x0;
    setvbuf(stdin, (char *)0x0, 2, 0);
    setvbuf(stdout, (char *)0x0, 2, 0);
    alarm(0x3c);
    FUN_001012c9();
    tVar3 = time((time_t *)0x0);
    srand(((int)tVar3 / 10) * 10);
    local_58 = (int *)mmap((void *)0x0, 0x800000, 2, 0x22, -1, 0);
    local_48 = local_58;
    if (local_58 != (int *)0xffffffffffffffff) {
        for (local_68 = 0; piVar1 = local_58, local_68 < 0x200000; local_68 = local_68 + 1) {
            local_58 = local_58 + 1;
            iVar2 = rand();
            *piVar1 = iVar2;
        }
        mprotect(local_48, 0x800000, 5);
        printf("mem: %p\n", local_48);
        lVar4 = getrandom(&local_60, 8, 1);
        if (lVar4 == 8) {
            local_60 = (void *)((ulong)local_60 & 0x7ffffffff000);
            local_50 = mmap(local_60, 0x1000, 3, 0x132, -1, 0);
            if (local_50 != (void *)0xffffffffffffffff) {
                printf("inz: ");
                read(0, local_50, 0x200);
                sleep(1);
                return ZEXT816(0);
            }
        }
    }
    puts(":(");
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return CONCAT88(extraout_RDX, 1);
    }
    __stack_chk_fail();
}
