
void setup(void) {
    setvbuf(stdout, (char *)0x0, 2, 0);
    setvbuf(stderr, (char *)0x0, 2, 0);
    setvbuf(stdin, (char *)0x0, 2, 0);
    return;
}

void printBanner(void) {
    puts("-------------------------------------");
    puts("|Numerology Server v0.1             |");
    puts("|Telling you who you are since 2021!|");
    puts("-------------------------------------\n");
    return;
}

void calcTrait(char *param_1) {
    size_t sVar1;
    int local_20;
    int local_1c;

    local_1c = 0;
    local_20 = 0;
    while (true) {
        sVar1 = strlen(param_1);
        if (sVar1 <= (ulong)(long)local_20)
            break;
        local_1c = local_1c + param_1[local_20];
        local_20 = local_20 + 1;
    }
    printf("According to your name your main trait is ");
    local_1c = local_1c % 10;
    if (local_1c == 0) {
        printf("unknown");
    }
    if (local_1c == 1) {
        printf("a mistery");
    }
    if (local_1c == 2) {
        printf("really hard to discern");
    }
    if (local_1c == 3) {
        printf("uuuuh... cool?");
    }
    if (local_1c == 4) {
        printf("something you should ask someone else");
    }
    if (local_1c == 5) {
        printf("a secret");
    }
    if (local_1c == 6) {
        printf("restricted information");
    }
    if (local_1c == 7) {
        printf("not what you think");
    }
    if (local_1c == 8) {
        printf("**REDACTED**");
    }
    if (local_1c == 9) {
        printf("not currently available...");
    }
    putchar(10);
    return;
}

void numerologyCalc(void) {
    int iVar1;
    char local_78[47];
    undefined local_49;
    undefined8 local_48;
    undefined8 local_40;
    undefined8 local_38;
    undefined8 local_30;
    undefined8 local_28;
    undefined8 local_20;
    char local_d;
    int local_c;

    local_48 = 0x6f6f6f6f6c6c6548;
    local_40 = 0x6f6f6f6f6f6f6f6f;
    local_38 = 0x6f6f6f6f6f6f6f6f;
    local_30 = 0x6f6f6f6f6f6f6f6f;
    local_28 = 0x206f6f6f;
    local_20 = 0;
    printf("Who are you?: ");
    for (local_c = 0; local_c < 0x30; local_c = local_c + 1) {
        iVar1 = getchar();
        local_d = (char)iVar1;
        if (local_d == '\n')
            break;
        local_78[local_c] = local_d;
    }
    if (local_c < 0x30) {
        local_78[local_c] = '\0';
    } else {
        local_49 = 0;
    }
    memcpy((void *)((long)&local_28 + 4), local_78, (long)(local_c + 1));
    printf("%s\n\n", &local_48);
    calcTrait(local_78);
    return;
}

void main(void) {
    setup();
    printBanner();
    numerologyCalc();
    exit(0);
}
