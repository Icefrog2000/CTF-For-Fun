
undefined8 *initialize(void) {
    undefined8 *puVar1;

    puVar1 = (undefined8 *)malloc(0x10);
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 1) = 0;
    return puVar1;
}

void menu(void) {
    long in_FS_OFFSET;
    char local_28[24];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    puts("1. Add user.");
    puts("2. Remove user.");
    puts("3. Edit user.");
    puts("4. Swap users.");
    puts("5. List all users.");
    puts("6. Exit.");
    printf("\n> ");
    fgets(local_28, 0x10, stdin);
    atoi(local_28);
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

void main(void) {
    undefined4 uVar1;
    int iVar2;
    undefined8 uVar3;

    uVar3 = initialize();
    puts("Terrible C Database v0.1a\n");
    do {
        uVar1 = menu();
        switch (uVar1) {
            default:
                puts("Invalid choice.\n");
                break;
            case 1:
                add_user(uVar3);
                break;
            case 2:
                iVar2 = print_database(uVar3);
                if (iVar2 != 0) {
                    remove_user(uVar3);
                }
                break;
            case 3:
                iVar2 = print_database(uVar3);
                if (iVar2 != 0) {
                    edit_user(uVar3);
                }
                break;
            case 4:
                iVar2 = print_database(uVar3);
                if (iVar2 != 0) {
                    swap_users(uVar3);
                }
                break;
            case 5:
                print_database(uVar3);
                break;
            case 6:
                exit(0);
        }
    } while (true);
}

void add_user(void **param_1) {
    uint uVar1;
    long lVar2;
    void *pvVar3;
    size_t sVar4;
    long in_FS_OFFSET;
    size_t local_28;
    long local_20;

    local_20 = *(long *)(in_FS_OFFSET + 0x28);
    if (param_1 == (void **)0x0) {
        puts("Database not initialized.\n");
    } else {
        uVar1 = *(uint *)(param_1 + 1);
        *(uint *)(param_1 + 1) = uVar1 + 1;
        pvVar3 = realloc(*param_1, (ulong) * (uint *)(param_1 + 1) * 8);
        *param_1 = pvVar3;
        *(undefined8 *)((long)*param_1 + (ulong)uVar1 * 8) = 0;
        printf("Enter username: ");
        local_28 = 0;
        getline((char **)((ulong)uVar1 * 8 + (long)*param_1), &local_28, stdin);
        lVar2 = *(long *)((long)*param_1 + (ulong)uVar1 * 8);
        sVar4 = strcspn(*(char **)((long)*param_1 + (ulong)uVar1 * 8), "\n");
        *(undefined *)(sVar4 + lVar2) = 0;
        puts("User added.\n");
    }
    if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

void remove_user(long *param_1) {
    uint uVar1;
    long in_FS_OFFSET;
    uint local_34;
    uint local_30;
    char local_28[24];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    printf("Enter entry of user to remove: ");
    fgets(local_28, 0x10, stdin);
    uVar1 = atoi(local_28);
    if (*(uint *)(param_1 + 1) <= uVar1) {
        puts("Invalid entry.\n");
        goto LAB_004018fa;
    }
    free(*(void **)(*param_1 + (ulong)uVar1 * 8));
    *(undefined8 *)(*param_1 + (ulong)uVar1 * 8) = 0;
    for (local_34 = 0; local_34 < *(uint *)(param_1 + 1); local_34 = local_34 + 1) {
        local_30 = local_34;
        if (*(long *)(*param_1 + (long)(int)local_34 * 8) == 0)
            goto LAB_004018b7;
    }
    goto LAB_004018dd;
LAB_004018b7:
    while (local_30 = local_30 + 1, local_30 < *(uint *)(param_1 + 1)) {
        *(undefined8 *)((long)(int)local_30 * 8 + -8 + *param_1) =
            *(undefined8 *)(*param_1 + (long)(int)local_30 * 8);
    }
LAB_004018dd:
    *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + -1;
    puts("Removed user.\n");
LAB_004018fa:
    if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
        return;
    }
    __stack_chk_fail();
}

void edit_user(long *param_1) {
    undefined8 uVar1;
    long lVar2;
    uint uVar3;
    size_t sVar4;
    long in_FS_OFFSET;
    char local_38[24];
    long local_20;

    local_20 = *(long *)(in_FS_OFFSET + 0x28);
    printf("Enter entry of user to edit: ");
    fgets(local_38, 0x10, stdin);
    uVar3 = atoi(local_38);
    if (uVar3 < *(uint *)(param_1 + 1)) {
        uVar1 = *(undefined8 *)(*(long *)(*param_1 + (ulong)uVar3 * 8) + -8);
        printf("\n[*] Username must be less than %lu characters long.\n");
        printf("Enter new username: ");
        fgets(*(char **)(*param_1 + (ulong)uVar3 * 8), (uint)uVar1 & 0xfffffffc, stdin);
        lVar2 = *(long *)(*param_1 + (ulong)uVar3 * 8);
        sVar4 = strcspn(*(char **)(*param_1 + (ulong)uVar3 * 8), "\n");
        *(undefined *)(sVar4 + lVar2) = 0;
        puts("User changed.\n");
    } else {
        puts("Invalid entry.\n");
    }
    if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

void swap_users(long *param_1) {
    uint uVar1;
    uint uVar2;
    long in_FS_OFFSET;
    char local_28[16];
    undefined8 local_18;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    if (*(uint *)(param_1 + 1) < 2) {
        puts("Not enough users to swap.\n");
    } else {
        printf("Enter entry of user to swap: ");
        fgets(local_28, 0x18, stdin);
        uVar1 = atoi(local_28);
        if (uVar1 < *(uint *)(param_1 + 1)) {
            local_18 = *(undefined8 *)(*param_1 + (ulong)uVar1 * 8);
            printf("Enter entry of user to swap with: ");
            fgets(local_28, 0x18, stdin);
            uVar2 = atoi(local_28);
            if ((uVar2 < *(uint *)(param_1 + 1)) && (uVar1 != uVar2)) {
                *(undefined8 *)((ulong)uVar1 * 8 + *param_1) = *(undefined8 *)(*param_1 + (ulong)uVar2 * 8);
                *(undefined8 *)((ulong)uVar2 * 8 + *param_1) = local_18;
                puts("Swapped users.\n");
            } else {
                puts("Invalid entry.\n");
            }
        } else {
            puts("Invalid entry.\n");
        }
    }
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28))
    {
        __stack_chk_fail();
    }
    return;
}

undefined4 print_database(long *param_1) {
    undefined4 uVar1;
    uint local_c;

    if (((param_1 == (long *)0x0) || (*param_1 == 0)) || (*(int *)(param_1 + 1) == 0))
    {
        puts("No users in database.\n");
        uVar1 = 0;
    } else {
        for (local_c = 0; local_c < *(uint *)(param_1 + 1); local_c = local_c + 1) {
            if (*(long *)(*param_1 + (long)(int)local_c * 8) != 0) {
                printf("Entry: %d, user: %s\n", (ulong)local_c,
                       *(undefined8 *)(*param_1 + (long)(int)local_c * 8));
            }
        }
        puts("");
        uVar1 = *(undefined4 *)(param_1 + 1);
    }
    return uVar1;
}
