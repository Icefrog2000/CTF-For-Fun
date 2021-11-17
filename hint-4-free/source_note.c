#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 0x7ffff7fba058
struct luu_metedata_arr {
    void* dia_chi_cua_heap;
    int max;
    int count;
};

// bat dau tu 0x7ffff7fb8050
struct note {
    char name_note[0x100];
    long length;
    char* note_content;
    long bit;
    void* function_free;
};

long* srote_note_arr; //0x4050e0
long* read_only; // 0x4030c4
// 0x401970
void zone_create_something(void) {
    zone_create(&read_only, 0x120);
    zone_create("note_array", 0x10);
    return;
}

// 0x401490
void **add_arr(void **param_1, unsigned int param_2) {
    void *pvVar1;
    void **local_10;

    if (param_1 == (void **)0x0) {
        local_10 = (void **)zone_alloc("note_array");
        *(unsigned int *)(local_10 + 1) = param_2;
        *(int *)((long)local_10 + 0xc) = 0;
        pvVar1 = malloc((unsigned long)param_2 << 3);
        *local_10 = pvVar1;
        memset(*local_10, 0, 8);
    }
    else {
        local_10 = param_1;
        if (param_2 < *(unsigned int *)(param_1 + 1)) {
            *(unsigned int *)(param_1 + 1) = param_2;
            pvVar1 = realloc(*param_1, (unsigned long)param_2 << 3);
            *param_1 = pvVar1;
        }
    }
    return local_10;
}

// 0x401440
void call_free_func(int *param_1) {
    if ((param_1 != (int *)0x0) && (*param_1 = *param_1 + -1, *param_1 == 0)) {
        (**(code **)(param_1 + 2))(param_1);
    }
    return;
}

void FUN_004018c0(void **param_1) {
    unsigned int local_14;

    if (*param_1 != (void *)0x0) {
        for (local_14 = 0; local_14 < *(unsigned int *)((long)param_1 + 0xc); local_14 = local_14 + 1) {
            if (*(long *)((long)*param_1 + (long)(int)local_14 * 8) != 0) {
                call_free_func(*(long *)((long)*param_1 + (long)(int)local_14 * 8) + 0x110);
            }
        }
        free(*param_1);
    }
    zone_free("note_array", param_1);
    return;
}

// 0x4019a0
void read_input(long param_1, unsigned int param_2) {
    int iVar1;
    unsigned int local_18;

    local_18 = 0;
    while (true) {
        if (param_2 <= local_18) {
            return;
        }
        iVar1 = fgetc(stdin);
        if ((char)iVar1 == '\n')
            break;
        *(char *)(param_1 + (int)local_18) = (char)iVar1;
        local_18 = local_18 + 1;
    }
    *(void *)(param_1 + (int)local_18) = 0;
    return;
}

// 0x401380
void clean(long param_1) {
    if (param_1 != 0) {
        if (*(long *)(param_1 + -8) != 0) {
            free(*(void **)(param_1 + -8));
        }
        zone_free(&read_only, param_1 + -0x110);
        return;
    }
    __assert_fail("ref != NULL", "/home/notes/src/note.c", 0x24, "void Note_Dealloc(reference_t)");
}

// 0x401a20
void read_long(void) {
    char local_18[16];

    memset(local_18, 0, 0x10);
    read_input(local_18);
    strtoul(local_18, (char **)0x0, 10);
    return;
}

// 0x401250
void assign_free_func(int *param_1,long param_2) {
  if (param_1 != (int *)0x0) {
    *param_1 = 1;
    *(long *)(param_1 + 2) = param_2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("ref != NULL","/home/notes/src/note.c",0xd,
                "void reference_init(reference_t, void (*)(reference_t))");
}

// 0x4012c0
void store_metadata(void *param_1, void *param_2, long param_3, long param_4) {
    if (param_1 != (void *)0x0) {
        memset(param_1, 0, 0x100);
        memcpy(param_1, param_2, 0xff);
        if (param_4 != 0) {
            *(long *)((long)param_1 + 0x100) = param_3;
            *(long *)((long)param_1 + 0x108) = param_4;
        }
        assign_free_func((long)param_1 + 0x110, clean);
        return;
    }
    __assert_fail("a_note != NULL", "/home/notes/src/note.c", 0x14,
                  "void Note_Init(Note_t, const char *, unsigned int64_t, char *)");
}

// 0x401410
void increase_count(int *param_1) {
    if (param_1 != (int *)0x0) {
        *param_1 = *param_1 + 1;
    }
    return;
}

// 0x401810
long get_member(long *param_1, unsigned int param_2) {
    long local_10;

    if (param_1 == (long *)0x0) {
        local_10 = 0;
    }
    else {
        if (param_2 < *(unsigned int *)((long)param_1 + 0xc)) {
            if (*(long *)(*param_1 + (unsigned long)param_2 * 8) != 0) {
                increase_count(*(long *)(*param_1 + (unsigned long)param_2 * 8) + 0x110);
            }
            local_10 = *(long *)(*param_1 + (unsigned long)param_2 * 8);
        }
        else {
            local_10 = 0;
        }
    }
    return local_10;
}

void FUN_00401550(long *param_1, long param_2) {
    unsigned int uVar1;

    if ((param_1 != (long *)0x0) && (*(int *)((long)param_1 + 0xc) + 1U < *(unsigned int *)(param_1 + 1))) {
        if (param_2 != 0) {
            increase_count();
        }
        uVar1 = *(unsigned int *)((long)param_1 + 0xc);
        *(unsigned int *)((long)param_1 + 0xc) = uVar1 + 1;
        *(long *)(*param_1 + (unsigned long)uVar1 * 8) = param_2;
    }
    return;
}

// 0x4015e0
void save(long *param_1, unsigned int param_2, long param_3) {
    unsigned int local_24;

    if (param_1 != (long *)0x0) {
        if (*(unsigned int *)(param_1 + 1) <= *(int *)((long)param_1 + 0xc) + 1U) {
            add_arr(param_1);
        }
        if ((param_2 < *(unsigned int *)(param_1 + 1)) &&
            (*(int *)((long)param_1 + 0xc) + 1U < *(unsigned int *)(param_1 + 1)))
        {
            local_24 = param_2;
            if (param_2 < *(unsigned int *)((long)param_1 + 0xc)) {
                for (; local_24 < *(unsigned int *)((long)param_1 + 0xc); local_24 = local_24 + 1) {
                    *(long *)(*param_1 + (unsigned long)(local_24 + 1) * 8) =
                        *(long *)(*param_1 + (unsigned long)local_24 * 8);
                }
                if (param_3 != 0) {
                    increase_count(param_3 + 0x110);
                }
                *(long *)(*param_1 + (unsigned long)param_2 * 8) = param_3;
                *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + 1;
            }
            else {
                FUN_00401550(param_1, param_3);
            }
        }
    }
    return;
}

// 0x401710
void delete_note(long *param_1, unsigned int param_2) {
    unsigned int local_18;

    if ((param_1 != (long *)0x0) && (param_2 < *(unsigned int *)((long)param_1 + 0xc))) {
        if (*(long *)(*param_1 + (unsigned long)param_2 * 8) != 0) {
            call_free_func(*(long *)(*param_1 + (unsigned long)param_2 * 8) + 0x110);
        }
        local_18 = param_2;
        if (param_2 + 1 == *(int *)((long)param_1 + 0xc)) {
            *(long *)(*param_1 + (unsigned long)param_2 * 8) = 0;
        }
        else {
            for (; local_18 < *(unsigned int *)((long)param_1 + 0xc); local_18 = local_18 + 1) {
                *(long *)(*param_1 + (unsigned long)local_18 * 8) =
                    *(long *)(*param_1 + (unsigned long)(local_18 + 1) * 8);
            }
        }
        *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + -1;
    }
    return;
}

// 0x401a70
void encrypt(long param_1, unsigned long param_2, long param_3, unsigned long param_4) {
    int local_2c;

    if (param_4 != 0) {
        for (local_2c = 0; (unsigned long)(long)local_2c < param_2; local_2c = local_2c + 1) {
            *(byte *)(param_1 + local_2c) =
                *(byte *)(param_1 + local_2c) ^ 
                *(byte *)(param_3 + (unsigned long)(long)local_2c % param_4);
        }
    }
    return;
}

// 0x401af0
long main(void) {
    bool bVar1;
    int iVar2;
    void *pvVar3;
    long lVar4;
    char *pcVar5;
    size_t sVar6;
    bool local_29d;
    unsigned int local_240;
    char *local_238;
    char *local_230;
    char local_228[12];
    void auStack540[500];
    void *local_28;
    unsigned int local_1c;
    unsigned int local_18;
    int local_14;
    int local_10;
    int local_c;

    local_c = 0;
    local_230 = (char *)0x0;
    bVar1 = true;
    zone_create_something();
    setvbuf(stdin, (char *)0x0, 2, 0);
    setvbuf(stdout, (char *)0x0, 2, 0);
    srote_note_arr = (long *)0x0;
    srote_note_arr = (long *)add_arr(0);
    if (srote_note_arr == (long *)0x0) {
        /* WARNING: Subroutine does not return */
        __assert_fail("gNoteArray != NULL", "/home/notes/src/main.c", 0x50, "int main()");
    }
    do {
        if (!bVar1) {
            if ((local_230 != (char *)0x0) && (local_230 != (char *)0x0)) {
                call_free_func(local_230 + 0x110);
            }
            FUN_004018c0(srote_note_arr);
            return 0;
        }
        puts("======== Note Manager ========");
        puts("1. Create Note");
        puts("2. Edit Note");
        puts("3. Save Note");
        puts("4. Copy Note");
        puts("5. List Note");
        puts("6. Remove Note");
        puts("7. Encrypt Note");
        puts("8. Decrypt Note");
        puts("9. Exit");
        printf("$ ");
        local_10 = read_long();
        switch (local_10) {
        case 1:
            if ((local_230 != (char *)0x0) && (local_230 != (char *)0x0)) {
                call_free_func(local_230 + 0x110);
            }
            local_230 = (char *)zone_alloc(&read_only);
            printf("Note Name: ");
            memset(local_228, 0, 0x200);
            read_input(local_228);
            printf("How many words do you want? ");
            local_1c = read_long();
            if (0x1000 < local_1c) {
                local_1c = 0x1000;
            }aveNote
            local_28 = (void *)0x0;
            if (local_1c != 0) {
                local_28 = malloc((unsigned long)local_1c);
                memset(local_28, 0, (unsigned long)local_1c);
                puts("Enter your content:");
                fread(local_28, 1, (unsigned long)local_1c, stdin);
            }
            store_metadata(local_230, local_228, local_1c);
            puts("Done.");
            break;
        case 2:
            if ((local_230 == (char *)0x0) || (iVar2 = strncmp("(Encrypted)", local_230, 0xb), iVar2 == 0)) {
            LAB_00401f29:
                printf("Which note do you want to edit?");
                local_14 = read_long();
                local_238 = (char *)get_member(srote_note_arr);
                if (local_238 == (char *)0x0) {
                    printf("Your requested note doesn\'t exists\n");
                    break;
                }
                iVar2 = strncmp("(Encrypted)", local_230, 0xb);
                if (iVar2 == 0) {
                    printf("Unable to edit encrypted note.\n");
                    break;
                }
            }
            else {
                do {
                    local_228[0] = '\0';
                    printf("Do you want to edit this note \"%s\" ? (y/n)", local_230);
                    read_input(local_228);
                    local_29d = local_228[0] != 'y' && local_228[0] != 'n';
                } while (local_29d);
                if (local_228[0] != 'y')
                    goto LAB_00401f29;
                if (local_230 != (char *)0x0) {
                    increase_count(local_230 + 0x110);
                }
                local_238 = local_230;
            }
            if (1 < *(unsigned int *)(local_238 + 0x110)) {
                if (local_238 != (char *)0x0) {
                    call_free_func(local_238 + 0x110);
                }
                local_230 = (char *)zone_alloc(&read_only);
                local_28 = malloc(*(size_t *)(local_238 + 0x100));
                memcpy(local_28, *(void **)(local_238 + 0x108), *(size_t *)(local_238 + 0x100));
                store_metadata(local_230, local_238, *(long *)(local_238 + 0x100), local_28);
                save(srote_note_arr, local_14, local_230);
                local_238 = local_230;
            }
            printf("Note Name: ");
            memset(local_228, 0, 0x1ff);
            read_input(local_228, 0xff);
            sVar6 = strlen(local_228);
            memcpy(local_238, local_228, sVar6 & 0xffffffff);
            local_238[sVar6 & 0xffffffff] = '\0';
            printf("How many words do you want? ");
            local_1c = read_long();
            if (0x1000 < local_1c) {
                local_1c = 0x1000;
            }
            if (*(unsigned long *)(local_238 + 0x100) <= (unsigned long)local_1c &&
                (unsigned long)local_1c != *(unsigned long *)(local_238 + 0x100))
            {
                pvVar3 = realloc(*(void **)(local_238 + 0x108), (unsigned long)local_1c);
                *(void **)(local_238 + 0x108) = pvVar3;
                *(unsigned long *)(local_238 + 0x100) = (unsigned long)local_1c;
            }
            fread(*(void **)(local_238 + 0x108), 1, (unsigned long)local_1c, stdin);
            if (local_238 != (char *)0x0) {
                call_free_func(local_238 + 0x110);
            }
            puts("Done.");
            break;
        case 3:
            if (local_230 == (char *)0x0) {
                puts("You don\'t have note to save");
            }
            else {
                printf("Which idx do you want to save?");
                local_14 = read_long();
                save(srote_note_arr, local_14, local_230);
                puts("Done.");
            }
            break;
        case 4:
            printf("Which note do you want to copy?");
            local_14 = read_long();
            lVar4 = get_member(srote_note_arr);
            if (lVar4 == 0) {
                printf("Your note at index %d does not exist\n");
            }
            else {
                printf("Which idx do you wanna save?");
                local_14 = read_long();
                save(srote_note_arr, local_14, lVar4);
                if (lVar4 != 0) {
                    call_free_func(lVar4 + 0x110);
                }
                puts("Done.");
            }
            break;
        case 5:
            if (*(int *)((long)srote_note_arr + 0xc) == 0) {
                printf("Note Database is empty\n");
            }
            else {
                printf("Notes: \n");
                for (local_18 = 0; local_18 < *(unsigned int *)((long)srote_note_arr + 0xc); local_18 = local_18 + 1)
                {
                    printf("%d. [%s] %lld\n", (unsigned long)local_18,
                           *(long *)(*srote_note_arr + (unsigned long)local_18 * 8),
                           *(long *)(*(long *)(*srote_note_arr + (unsigned long)local_18 * 8) + 0x100));
                }
                printf("Which note do you want to read?");
                local_14 = read_long();
                lVar4 = get_member(srote_note_arr);
                if (lVar4 == 0) {
                    printf("Note at %d do not exist\n");
                }
                else {
                    printf("Note [%s]\n", lVar4);
                    puts("Content:");
                    fwrite(*(void **)(lVar4 + 0x108), 1, *(size_t *)(lVar4 + 0x100), stdout);
                    printf("\n");
                    if (lVar4 != 0) {
                        call_free_func(lVar4 + 0x110);
                    }
                    puts("Done.");
                }
            }
            break;
        case 6:
            printf("Which note do you want to remove?");
            local_14 = read_long();
            delete_note(srote_note_arr);
            puts("Done.");
            break;
        case 7:
            printf("Which note do you want to encrypt?");
            local_14 = read_long();
            pcVar5 = (char *)get_member(srote_note_arr);
            if (pcVar5 == (char *)0x0) {
                printf("Note at %d does not exists.");
            }
            else {
                printf("Key length: ");
                local_240 = read_long();
                if (0x40 < local_240) {
                    local_240 = 0x40;
                }
                memset(local_228, 0, (unsigned long)local_240);
                read_input(local_228, local_240);
                encrypt(*(long *)(pcVar5 + 0x108), *(long *)(pcVar5 + 0x100), local_228);
                sVar6 = strlen(pcVar5);
                memcpy(local_228, pcVar5, sVar6 & 0xffffffff);
                local_228[sVar6 & 0xffffffff] = '\0';
                sprintf(pcVar5, "(Encrypted)%s", local_228);
                if (pcVar5 != (char *)0x0) {
                    call_free_func(pcVar5 + 0x110);
                }
                puts("Done.");
            }
            break;
        case 8:
            printf("Which note do you want to decrypt?");
            local_14 = read_long();
            pcVar5 = (char *)get_member(srote_note_arr);
            if (pcVar5 == (char *)0x0) {
                printf("Note at %d does not exists.");
            }
            else {
                iVar2 = strncmp("(Encrypted)", pcVar5, 0xb);
                if (iVar2 == 0) {
                    printf("Key length: ");
                    local_240 = read_long();
                    if (0x40 < local_240) {
                        local_240 = 0x40;
                    }
                    memset(local_228, 0, (unsigned long)local_240);
                    read_input(local_228, local_240);
                    encrypt(*(long *)(pcVar5 + 0x108), *(long *)(pcVar5 + 0x100), local_228,
                                 local_240);
                    sVar6 = strlen(pcVar5);
                    memset(local_228, 0, sVar6 & 0xffffffff);
                    memcpy(local_228, pcVar5, sVar6 & 0xffffffff);
                    memcpy(pcVar5, auStack540, (sVar6 & 0xffffffff) - 0xb);
                    pcVar5[sVar6 & 0xffffffff] = '\0';
                    if (pcVar5 != (char *)0x0) {
                        call_free_func(pcVar5 + 0x110);
                    }
                    puts("Done.");
                }
                else {
                    printf("This note \"%s\" was not encrypted");
                }
            }
            break;
        case 9:
            bVar1 = false;
        }
    } while (true);
}