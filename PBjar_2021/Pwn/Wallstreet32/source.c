undefined4 main(void) {
    uint __seed;
    int local_d4;
    undefined local_d0[192];
    undefined *local_10;

    local_10 = &stack0x00000004;
    setbuf(stdout, (char *)0x0);
    setbuf(stderr, (char *)0x0);
    __seed = time((time_t *)0x0);
    srand(__seed);
    puts("You are at a familiar seeming place, somewhere between 32nd and wall street.");
    puts("Welcome back to the trading app!\n");
    puts("What would you like to do?");
    puts("1) Buy some stonks!");
    __isoc99_scanf("%d", &local_d4);
    if (local_d4 == 1) {
        init_stonks(local_d0);
        buy_stonks(local_d0);
    }
    return 0;
}

void init_stonks(int param_1) {
    undefined4 uVar1;
    int local_10;

    puts("\nBuying stonks...");
    for (local_10 = 0; local_10 < 0x30; local_10 = local_10 + 1) {
        uVar1 = pick_symbol_with_AI();
        *(undefined4 *)(local_10 * 4 + param_1) = uVar1;
    }
    return;
}

void *pick_symbol_with_AI(void) {
    void *pvVar1;
    int iVar2;
    int local_14;

    pvVar1 = calloc(5, 1);
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
        iVar2 = rand();
        *(char *)((int)pvVar1 + local_14) = (char)iVar2 % '\x1a' + 'A';
    }
    *(undefined *)((int)pvVar1 + 4) = 0;
    return pvVar1;
}

void buy_stonks(int param_1) {
    ssize_t sVar1;
    int local_14;
    int local_10;

    puts("What stonk do you want to see?");
    __isoc99_scanf("%d", &local_14);
    if ((-1 < local_14) && (local_14 < 0x30)) {
        puts(*(char **)(param_1 + local_14 * 4));
        puts("\nWhat is your API token?");
        getchar();
        sVar1 = read(0, user_buf, 300);
        user_buf[sVar1] = 0;
        puts("");
        local_10 = 0;
        while (true) {
            if (299 < local_10) {
                puts("Buying stonks with token:");
                printf(user_buf);
                return;
            }
            if ((int)(char)user_buf[local_10] - 0x41U < 0x38)
                break;
            local_10 = local_10 + 1;
        }
        (*(code *)((int)&_GLOBAL_OFFSET_TABLE_ +
                   *(int *)(&DAT_000120c8 + ((int)(char)user_buf[local_10] - 0x41U) * 4)))();
        return;
    }
    puts("You think we haven\'t fixed this STILL!");
    puts("Invalid index.");
    exit(0);
}