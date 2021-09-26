
undefined8 main(void) {
    char *__stat_loc;

    setbuf(stdout, (char *)0x0);
    __stat_loc = "Lets play a game";
    puts("Lets play a game");
    wait(__stat_loc);
    return 0;
}

__pid_t wait(void *__stat_loc) {
    __pid_t _Var1;
    ulong uVar2;
    char local_8d[5];
    char local_88[120];

    puts("Press enter to continue");
    getc(stdin);
    printf("Pick a number: ");
    fgets(local_8d, 5, stdin);
    uVar2 = strtol(local_8d, (char **)0x0, 10);
    snprintf(local_88, 100, "Your magic number is: %%%d$llx\n", uVar2 & 0xffffffff);
    printf(local_88);
    _Var1 = introduce();
    return _Var1;
}

void introduce(void) {
    puts("Are you ready to echo?");
    get_num_bytes();
    puts("That was fun!");
    return;
}

void get_num_bytes(void) {
    ulong uVar1;
    char local_1d[13];

    printf("How many bytes do you want to read (max 256)? ");
    fgets(local_1d, 5, stdin);
    uVar1 = strtol(local_1d, (char **)0x0, 10);
    if ((uint)uVar1 < 0x101) {
        echo(uVar1 & 0xffffffff);
        return;
    }
    puts("Don\'t break the rules!");
    return;
}

void get_lucky(void) {
    ulong uVar1;
    char local_8d[5];
    char local_88[120];

    printf("Pick a number: ");
    fgets(local_8d, 5, stdin);
    uVar1 = strtol(local_8d, (char **)0x0, 10);
    snprintf(local_88, 100, "Your magic number is: %%%d$llx\n", uVar1 & 0xffffffff);
    printf(local_88);
    return;
}

void echo(undefined4 param_1) {
    undefined local_108[256];

    echo_inner(local_108, param_1);
    return;
}

void echo_inner(void *param_1, int param_2) {
    size_t sVar1;

    sVar1 = fread(param_1, 1, (long)param_2, stdin);
    *(undefined *)((long)param_1 + (long)(int)sVar1) = 0;
    puts("You said:");
    printf("%s", param_1);
    return;
}