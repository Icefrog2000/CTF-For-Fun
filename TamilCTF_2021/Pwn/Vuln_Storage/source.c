
void main(void) {
    ssize_t sVar1;
    int local_144;
    int local_140;
    int local_13c;
    void *pvStack312;
    int aiStack304[58];
    char local_48[36];
    undefined4 local_24;
    void *local_20;
    ulong local_18;
    int local_10;
    uint local_c;

    puts("============================================================================");
    puts("Please don\'t pwn me.. My creator did not made me up with best code practises");
    puts("============================================================================");
    local_c = 0;
    do {
        printf("Storage space created %d/15\n\n", (ulong)local_c);
        puts(
            "1.Create storage space\n\n2.Destroy the storage space\n\n3.Edit the storage space\n\n4.View the storage space\n\n5.Exit\n");
        printf(">>");
        __isoc99_scanf(&DAT_0010213c);
        switch (local_24) {
            default:
                puts("\nInvalid Index\n");
                break;
            case 1:
                if (((int)local_c < 0xf) && (-1 < (int)local_c)) {
                    write(1, "\nEnter the size:", 0x10);
                    read(0, local_48, 0x1f);
                    local_18 = strtoul(local_48, (char **)0x0, 0);
                    if ((local_18 == 0x227ffb) || (((0x17 < local_18 && (local_18 < 0x3e9)) && (local_18 != 0)))) {
                        local_20 = malloc(local_18);
                        if (local_20 == (void *)0x0) {
                            puts("Chunk request failed");
                        } else {
                            (&pvStack312)[(long)(int)local_c * 2] = local_20;
                            aiStack304[(long)(int)local_c * 4] = (int)local_18;
                            memset(local_20, 0, 0x10);
                            local_c = local_c + 1;
                        }
                    } else {
                        puts("Request size should be between 24 and 1000");
                    }
                } else {
                    puts("Only 15 requests available");
                }
                break;
            case 2:
                write(1, "\nEnter the index:", 0x11);
                __isoc99_scanf(&DAT_0010213c);
                if ((local_13c < 0) || (0xe < local_13c)) {
                    puts("\nTrying out of bounds huh!!Don\'t make me laugh!! Try better!!\n");
                } else {
                    if (((&pvStack312)[(long)local_13c * 2] == (void *)0x0) || ((int)local_c <= local_13c)) {
                        puts("Trying UAF or Double free is a joke here\n");
                    } else {
                        free((&pvStack312)[(long)local_13c * 2]);
                        (&pvStack312)[(long)local_13c * 2] = (void *)0x0;
                        puts("\nFree\n");
                    }
                }
                break;
            case 3:
                write(1, "\nEnter the index:", 0x11);
                __isoc99_scanf(&DAT_0010213c);
                if ((local_140 < 0) || (0xe < local_140)) {
                    puts("But we cannot give you any integer bugs to exploit");
                } else {
                    if (((&pvStack312)[(long)local_140 * 2] == (void *)0x0) || ((int)local_c <= local_140)) {
                        puts("What are you even trying uaf or double free!!Nothing works here");
                    } else {
                        write(1, "\nEnter the data:", 0x10);
                        sVar1 = read(0, (&pvStack312)[(long)local_140 * 2], (long)aiStack304[(long)local_140 * 4]);
                        local_10 = (int)sVar1;
                        memset((void *)((long)(int)sVar1 + (long)(&pvStack312)[(long)local_140 * 2]), 0, 1);
                        puts("Data successfully written on chunk");
                    }
                }
                break;
            case 4:
                write(1, "\nEnter the index:", 0x11);
                __isoc99_scanf(&DAT_0010213c);
                if ((local_144 < 0) || (0xe < local_144)) {
                    puts("Sorry no out of bound read using integer bugs");
                } else {
                    if (((&pvStack312)[(long)local_144 * 2] == (void *)0x0) || ((int)local_c <= local_144)) {
                        puts("Guys!! Don\'t be so stupid to try read after after here!!");
                    } else {
                        write(1, "\nHere is your chunk contents\n", 0x1c);
                        write(1, (&pvStack312)[(long)local_144 * 2], (long)aiStack304[(long)local_144 * 4]);
                    }
                }
                break;
            case 5:
                puts("\nExit\n");
                exit(0);
        }
    } while (true);
}
