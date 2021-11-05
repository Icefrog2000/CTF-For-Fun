#include <stdio.h>

void setup(void) {
    setvbuf(stdout, (char *)0x0, 2, 0);
    setvbuf(stderr, (char *)0x0, 2, 0);
    setvbuf(stdin, (char *)0x0, 2, 0);
    return;
}

char *load_flag(void) {
    char *__s;
    FILE *__stream;

    __s = (char *)malloc(0x80);
    __stream = fopen("flag.txt", "r");
    fgets(__s, 0x7f, __stream);
    fclose(__stream);
    return __s;
}

void banner(void) {
    puts("================================");
    puts("Welcome to note server 2021");
    puts("Now with stack canaries!!!");
    puts("================================");
    return;
}

void main(void) {
    char* uVar1;

    setup();
    uVar1 = load_flag();
    banner();
    note_server();
    return;
}

void note_server(void) {
    int iVar1;
    char *__s;
    int local_120;
    char local_119;
    char local_118[264];
    long local_10;

    local_10 = setup;
    memset(local_118, 0, 0x100);
    do {
        while (1) {
            while (1) {
                puts("\n1. Write note");
                puts("2. Read note");
                puts("3. Exit");
                printf("> ");
                __s = "%d";
                iVar1 = __isoc99_scanf("%d", &local_119);
                if (iVar1 == 1)
                    break;
                gets(__s);
            }
            if (local_119 == '\x03') {
                iVar1 = memcmp(&local_10, setup, 8);
                if (iVar1 == 0) {
                    return;
                }
                printf("Overflow attempt. Canary value > ");
                printf((char *)&local_10);
                /* WARNING: Subroutine does not return */
                exit(0);
            }
            if (local_119 < '\x04')
                break;
        LAB_001014cf:
            puts("Invalid option...\n");
        }
        if (local_119 == '\x01') {
            printf("Choose a note [0 - 7]: ");
            __isoc99_scanf("%d", &local_120);
            if ((local_120 < 0) || (7 < local_120)) {
                puts("Invalid note");
            } else {
                __isoc99_scanf(" %[^\n]", local_118 + (long)local_120 * 0x20);
            }
        } else {
            if (local_119 != '\x02')
                goto LAB_001014cf;
            printf("Choose a note [0 - 7]: ");
            __isoc99_scanf("%d", &local_120);
            if ((local_120 < 0) || (7 < local_120)) {
                puts("Invalid note");
            } else {
                puts(local_118 + (long)local_120 * 0x20);
            }
        }
    } while (1);
}