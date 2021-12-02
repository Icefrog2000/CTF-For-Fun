#include <stdio.h>
#include <sys/time.h>

char* DAT_00302018; // 0x302018

// 0x100b60
void setup(void) {
    time_t tVar1;
    unsigned int local_c;

    local_c = 0;
    setvbuf(stdout, (char *)0x0, 2, 0);
    setvbuf(stdin, (char *)0x0, 2, 0);
    tVar1 = time((time_t *)0x0);
    srand((unsigned int)tVar1);
    for (; (int)local_c < 0x10001; local_c = local_c & 0xfffff000) {
        local_c = rand();
    }
    DAT_00302018 = mmap((void *)(long)(int)local_c, 0x1000, 3, 0x22, -1, 0);
    if (DAT_00302018 == (void *)0xffffffffffffffff) {
        puts("mmap error");
        exit(0);
    }
    return;
}

// 0x100ca9
int read_int(void) {
    int iVar1;
    long in_FS_OFFSET;
    char local_28[24];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    iVar1 = __read_chk(0, local_28, 0xf, 0xf);
    if (iVar1 < 1) {
        puts("read error");
        exit(1);
    }
    iVar1 = atoi(local_28);
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return iVar1;
}

// 0x100e34
void FUN_00100e34(void) {
    printf("Your secret : %p\n", DAT_00302018);
    puts("Good bye ~");
    exit(0);
}

// 0x101117
void menu(void) {
    puts("==================================");
    puts("        Secret of my heart        ");
    puts("==================================");
    puts(" 1. Add a secret                  ");
    puts(" 2. show a secret                 ");
    puts(" 3. delete a secret               ");
    puts(" 4. Exit                          ");
    puts("==================================");
    printf("Your choice :");
    return;
}

// 0x10118f
void main(void) {
    int iVar1;

    setup();
    do {
        while (1) {
            while (1) {
                menu();
                iVar1 = read_int();
                if (iVar1 != 3)
                    break;
                delete_a_secret();
            }
            if (3 < iVar1)
                break;
            if (iVar1 == 1) {
                add_a_secret();
            } else {
                if (iVar1 == 2) {
                    show_a_secret();
                } else {
                LAB_0010120f:
                    puts("Invalid choice");
                }
            }
        }
        if (iVar1 == 4) {
            exit(0);
        }
        if (iVar1 != 0x1305)
            goto LAB_0010120f;
        FUN_00100e34();
    } while (1);
}

// 0x100c38
unsigned long read_input(void *param_1, unsigned int param_2) {
    int iVar1;
    unsigned long uVar2;

    uVar2 = read(0, param_1, (unsigned long)param_2);
    iVar1 = (int)uVar2;
    if (iVar1 < 1) {
        puts("read error");
        exit(1);
    }
    if (*(char *)((long)param_1 + (long)iVar1 + -1) == '\n') {
        *(char *)((long)param_1 + (long)iVar1 + -1) = 0;
    }
    return uVar2 & 0xffffffff;
}

void FUN_00100d27(size_t *param_1, size_t param_2) {
    int iVar1;
    void *pvVar2;

    *param_1 = param_2;
    printf("Name of heart :");
    read_input(param_1 + 1, 0x20);
    pvVar2 = malloc(param_2);
    param_1[5] = (size_t)pvVar2;
    if (param_1[5] == 0) {
        puts("Allocate Error !");
        exit(0);
    }
    printf("secret of my heart :");
    iVar1 = read_input(param_1[5], param_2 & 0xffffffff);
    *(char *)((long)iVar1 + param_1[5]) = 0;
    return;
}

// 0x100e6c
void add_a_secret(void) {
    int iVar1;
    int local_14;

    local_14 = 0;
    while (1) {
        if (99 < local_14) {
            puts("Fulled !!");
            return;
        }
        if (*(long *)((long)local_14 * 0x30 + DAT_00302018 + 0x28) == 0)
            break;
        local_14 = local_14 + 1;
    }
    printf("Size of heart : ");
    iVar1 = read_int();
    if (0x100 < (unsigned long)(long)iVar1) {
        puts("Too big !");
        return;
    }
    FUN_00100d27(DAT_00302018 + (long)local_14 * 0x30, (long)iVar1);
    puts("Done !");
    return;
}

// 0x100de4
void FUN_00100de4(long *param_1) {
    *param_1 = 0;
    memset(param_1 + 1, 0, 0x20);
    free((void *)param_1[5]);
    param_1[5] = 0;
    return;
}

// 0x10106d
void delete_a_secret(void) {
    unsigned int uVar1;

    printf("Index :");
    uVar1 = read_int();
    if (99 < uVar1) {
        puts("Out of bound !");
        exit(-2);
    }
    if (*(long *)((unsigned long)uVar1 * 0x30 + DAT_00302018 + 0x28) == 0) {
        puts("No such heap !");
    } else {
        FUN_00100de4((unsigned long)uVar1 * 0x30 + DAT_00302018);
        puts("Done !");
    }
    return;
}

// 0x100f3c
void show_a_secret(void) {
    unsigned int uVar1;

    printf("Index :");
    uVar1 = read_int();
    if (99 < uVar1) {
        puts("Out of bound !");
        exit(-2);
    }
    if (*(long *)((unsigned long)uVar1 * 0x30 + DAT_00302018 + 0x28) == 0) {
        puts("No such heap !");
    }
    else {
        printf("Index : %d\n", (unsigned long)uVar1);
        printf("Size : %lu\n", *(long *)((unsigned long)uVar1 * 0x30 + DAT_00302018));
        printf("Name : %s\n", (unsigned long)uVar1 * 0x30 + DAT_00302018 + 8);
        printf("Secret : %s\n", *(long *)((unsigned long)uVar1 * 0x30 + DAT_00302018 + 0x28));
    }
    return;
}
