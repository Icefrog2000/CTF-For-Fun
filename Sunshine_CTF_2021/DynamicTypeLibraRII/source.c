
void consume(void) {
    long lVar1;
    int iVar2;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    do {
        iVar2 = _IO_getc(stdin);
        if (iVar2 == 10)
            break;
    } while (iVar2 != -1);
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

undefined8 read_int(void) {
    long in_FS_OFFSET;
    undefined8 local_18;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    __isoc99_scanf(&DAT_00401630, &local_18);
    consume();
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return local_18;
}

undefined8 get_numsz(void) {
    long lVar1;
    undefined8 uVar2;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    printf(
        "What size of numbers do you need to crunch?\n[0]: 32-Bit Integer\n[1]: 64-Bit\n[2]: 64-Bit Floating Point\n> ");
    uVar2 = read_int();
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return uVar2;
}

undefined *type_to_fmt_spec(int param_1) {
    undefined *puVar1;
    long in_FS_OFFSET;

    if (param_1 == 1) {
        puVar1 = &DAT_00401625;
    } else {
        if (param_1 == 0) {
            puVar1 = &DAT_00401622;
        } else {
            if (param_1 == 2) {
                puVar1 = &DAT_00401629;
            } else {
                if (param_1 != 3) {
                    exit(1);
                }
                puVar1 = &DAT_0040162c;
            }
        }
    }
    if (*(long *)(in_FS_OFFSET + 0x28) != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return puVar1;
}

undefined8 type_to_sz(int param_1) {
    undefined8 uVar1;
    long in_FS_OFFSET;

    if (param_1 == 1) {
        uVar1 = 8;
    } else {
        if (param_1 == 0) {
            uVar1 = 4;
        } else {
            if (param_1 == 2) {
                uVar1 = 8;
            } else {
                if (param_1 != 3) {
                    exit(1);
                }
                uVar1 = 0x10;
            }
        }
    }
    if (*(long *)(in_FS_OFFSET + 0x28) != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return uVar1;
}

undefined4 *new_number(undefined4 param_1) {
    long lVar1;
    undefined uVar2;
    undefined4 *puVar3;
    undefined8 uVar4;
    byte bVar5;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    puVar3 = (undefined4 *)malloc(0xa6);
    *puVar3 = param_1;
    uVar4 = type_to_fmt_spec(param_1);
    *(undefined8 *)(puVar3 + 1) = uVar4;
    uVar2 = type_to_sz(param_1);
    *(undefined *)(puVar3 + 3) = uVar2;
    *(undefined *)((long)puVar3 + 0xd) = 0;
    bVar5 = 8;
    if (*(byte *)(puVar3 + 3) < 9) {
        bVar5 = *(byte *)(puVar3 + 3);
    }
    *(byte *)((long)puVar3 + 0xe) = 0x80 / bVar5;
    memset((void *)((long)puVar3 + 0x16), 0, 0x80);
    *(undefined4 **)((long)puVar3 + 0x96) = puVar3;
    *(code **)((long)puVar3 + 0x9e) = free;
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return puVar3;
}

ulong get_menuopt(void) {
    long lVar1;
    ulong uVar2;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    while (true) {
        printf(
            "What would you like to do?\n[0]: Add all numbers\n[1]: Insert a number\n[2]: Remove a number\n[3]: Print numbers\n[4]: Exit\n> ");
        uVar2 = read_int();
        if (uVar2 < 5)
            break;
        puts("\nInvalid.");
    }
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return uVar2;
}

undefined8 main(void) {
    long lVar1;
    undefined8 uVar2;
    ulong uVar3;
    size_t __size;
    void *__buf;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    puts("Hi! I\'m Big Byte, the Number Crunching Robot!");
    puts("Let\'s crunch some numbers!");
    uVar2 = get_numsz();
    uVar2 = new_number(uVar2);
    while (true) {
        uVar3 = get_menuopt();
        if (3 < uVar3)
            break;
        do_opt(uVar2, uVar3);
    }
    puts("Before you go, I want YOU to do some math!");
    printf("How big of a notebook do you need?\n> ");
    __size = read_int();
    malloc(__size);
    printf("Finally, what\'s your name?");
    __buf = calloc(1, 0x30);
    read(0, __buf, 0x2f);
    puts("Ok, bye!");
    free(__buf);
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return 0;
}

void do_opt(undefined8 param_1, long param_2) {
    long lVar1;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    if (param_2 == 1) {
        puts("Inserting a number...");
        do_ins(param_1);
    } else {
        if (param_2 == 0) {
            puts("Adding all numbers...");
            do_add(param_1);
        } else {
            if (param_2 == 2) {
                puts("Removing a number...");
                do_rem(param_1);
            } else {
                if (param_2 == 3) {
                    puts("Printing...");
                    do_prn(param_1);
                } else {
                    puts("\nInvalid.");
                }
            }
        }
    }
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

void do_ins(int *param_1) {
    int iVar1;
    long lVar2;
    long in_FS_OFFSET;

    lVar2 = *(long *)(in_FS_OFFSET + 0x28);
    if (*(byte *)((long)param_1 + 0xd) < *(byte *)((long)param_1 + 0xe)) {
        printf("What value?\n> ");
        iVar1 = *param_1;
        if (iVar1 == 1) {
            __isoc99_scanf(*(undefined8 *)(param_1 + 1),
                           (long)param_1 +
                               (long)(int)((uint) * (byte *)(param_1 + 3) * (uint) * (byte *)((long)param_1 + 0xd)) + 0x16);
        } else {
            if (iVar1 == 0) {
                __isoc99_scanf(*(undefined8 *)(param_1 + 1),
                               (long)param_1 +
                                   (long)(int)((uint) * (byte *)(param_1 + 3) *
                                               (uint) * (byte *)((long)param_1 + 0xd)) +
                                   0x16);
            } else {
                if (iVar1 == 2) {
                    __isoc99_scanf(*(undefined8 *)(param_1 + 1),
                                   (long)param_1 +
                                       (long)(int)((uint) * (byte *)(param_1 + 3) *
                                                   (uint) * (byte *)((long)param_1 + 0xd)) +
                                       0x16);
                } else {
                    if (iVar1 != 3)
                        goto LAB_0040110c;
                    __isoc99_scanf(*(undefined8 *)(param_1 + 1),
                                   (long)param_1 +
                                       (long)(int)((uint) * (byte *)(param_1 + 3) *
                                                   (uint) * (byte *)((long)param_1 + 0xd)) +
                                       0x16);
                }
            }
        }
        consume();
        *(char *)((long)param_1 + 0xd) = *(char *)((long)param_1 + 0xd) + '\x01';
    } else {
        puts("Full!");
    }
LAB_0040110c:
    if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
        return;
    }
    __stack_chk_fail();
}

void do_add(int *param_1) {
    int iVar1;
    long lVar2;
    long in_FS_OFFSET;
    byte local_40;
    byte local_3f;
    byte local_3e;
    byte local_3d;
    uint local_3c;
    long local_38;

    lVar2 = *(long *)(in_FS_OFFSET + 0x28);
    iVar1 = *param_1;
    if (iVar1 == 1) {
        local_38 = 0;
        local_3f = 0;
        while (local_3f < *(byte *)((long)param_1 + 0xd)) {
            local_3f = local_3f + 1;
            local_38 = local_38 +
                       *(long *)((long)param_1 +
                                 (long)(int)((uint) * (byte *)(param_1 + 3) * (uint)local_3f) + 0x16);
        }
        printf(*(char **)(param_1 + 1), local_38);
        putchar(10);
    } else {
        if (iVar1 == 0) {
            local_3c = 0;
            local_40 = 0;
            while (local_40 < *(byte *)((long)param_1 + 0xd)) {
                local_40 = local_40 + 1;
                local_3c = local_3c +
                           *(int *)((long)param_1 +
                                    (long)(int)((uint) * (byte *)(param_1 + 3) * (uint)local_40) + 0x16);
            }
            printf(*(char **)(param_1 + 1), (ulong)local_3c);
            putchar(10);
        } else {
            if (iVar1 == 2) {
                for (local_3e = 0; local_3e < *(byte *)((long)param_1 + 0xd); local_3e = local_3e + 1)
                {
                }
                printf(*(char **)(param_1 + 1));
                putchar(10);
            } else {
                if (iVar1 == 3) {
                    for (local_3d = 0; local_3d < *(byte *)((long)param_1 + 0xd); local_3d = local_3d + 1)
                    {
                    }
                    printf(*(char **)(param_1 + 1));
                    putchar(10);
                }
            }
        }
    }
    if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
        return;
    }
    __stack_chk_fail();
}

void do_rem(long param_1) {
    long lVar1;
    long in_FS_OFFSET;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    *(char *)(param_1 + 0xd) = *(char *)(param_1 + 0xd) + -1;
    if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

void do_prn(int *param_1) {
    int iVar1;
    long lVar2;
    long in_FS_OFFSET;
    byte local_12;
    byte local_11;

    lVar2 = *(long *)(in_FS_OFFSET + 0x28);
    puts("{");
    local_12 = 0;
    do {
        if (*(byte *)((long)param_1 + 0xd) <= local_12) {
            puts("};");
            if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
                return;
            }
            __stack_chk_fail();
        }
        printf("    [%02zu]: ", (ulong)local_12);
        iVar1 = *param_1;
        if (iVar1 == 1) {
            printf(*(char **)(param_1 + 1),
                   *(undefined8 *)((long)param_1 + (long)(int)((uint) * (byte *)(param_1 + 3) * (uint)local_12) + 0x16));
        LAB_004012e5:
            putchar(0x20);
            for (local_11 = 0; local_11 < *(byte *)(param_1 + 3); local_11 = local_11 + 1)
            {
                printf("%02x", (ulong) * (byte *)((long)param_1 +
                                                  (long)(int)((uint)local_11 +
                                                              (uint)local_12 * (uint) * (byte *)(param_1 + 3)) +
                                                  0x16));
            }
        } else {
            if (iVar1 == 0) {
                printf(*(char **)(param_1 + 1),
                       (ulong) * (uint *)((long)param_1 +
                                          (long)(int)((uint) * (byte *)(param_1 + 3) * (uint)local_12) + 0x16));
                goto LAB_004012e5;
            }
            if (iVar1 == 2) {
                printf(*(char **)((long)param_1 +
                                  (long)(int)((uint) * (byte *)(param_1 + 3) * (uint)local_12) + 0x16),
                       *(undefined8 *)(param_1 + 1));
                goto LAB_004012e5;
            }
            if (iVar1 == 3) {
                printf(*(char **)(param_1 + 1));
                goto LAB_004012e5;
            }
        }
        puts(";");
        local_12 = local_12 + 1;
    } while (true);
}
