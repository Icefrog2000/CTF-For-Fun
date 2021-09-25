// NAME 0x1040a0
// RANDBUF 0x1040c0
int init(EVP_PKEY_CTX *ctx) {
    int iVar1;

    setvbuf(stdin, (char *)0x0, 2, 0);
    iVar1 = setvbuf(stdout, (char *)0x0, 2, 0);
    return iVar1;
}

void print_menu(void) {
    puts("1. Set Username");
    puts("2. Print Username");
    printf("> ");
    return;
}

void get_num(void) {
    long in_FS_OFFSET;
    char local_1c[12];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    read(0, local_1c, 0xb);
    atoi(local_1c);
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

void main(EVP_PKEY_CTX *param_1) {
    int iVar1;

    init(param_1);
    puts("Welcome, what is your name?");
    read(0, NAME, 0x20);
    RANDBUF = "/dev/urandom";
    do {
        while (true) {
            while (true) {
                print_menu();
                iVar1 = get_num();
                if (iVar1 != 0x539)
                    break;
                game();
            }
            if (iVar1 < 0x53a)
                break;
        LAB_0010126c:
            puts("Invalid choice.");
        }
        if (iVar1 == 1) {
            set_username();
        } else {
            if (iVar1 != 2)
                goto LAB_0010126c;
            print_username();
        }
    } while (true);
}

void game(void) {
    int iVar1;
    FILE *__stream;
    long in_FS_OFFSET;
    int local_14;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    __stream = fopen(RANDBUF, "rb");
    fread(&local_14, 1, 4, __stream);
    printf("guess: ");
    iVar1 = get_num();
    if (iVar1 == local_14) {
        system("/bin/sh");
    }
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

void set_username(void) {
    FILE *__stream;
    size_t __n;

    puts("What would you like to change your username to?");
    __stream = stdin;
    __n = strlen(NAME);
    fread(NAME, 1, __n, __stream);
    return;
}

void print_username(void) {
    puts(NAME);
    return;
}