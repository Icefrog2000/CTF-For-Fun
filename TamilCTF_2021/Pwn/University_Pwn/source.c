
void main(void) {
    long in_FS_OFFSET;
    uint local_b94;
    int local_b90;
    uint local_b8c;
    ulong local_b88;
    void *local_b80;
    undefined local_b78[20];
    int iStack2916;
    char acStack2912[56];
    void *pvStack2856;
    int aiStack2848[698];
    char local_38[40];
    undefined8 local_10;

    local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
    setbuf(stdout, (char *)0x0);
    setbuf(stdin, (char *)0x0);
    local_b8c = 0;
    do {
        putchar(10);
        puts("===============================================");
        puts("Revaluation Panel of Akka University");
        puts("===============================================");
        printf("Remaining papers available %u/30\n\n", (ulong)local_b8c);
        write(1,
              "1.Evaluate a answer sheet\n\n2.Put arrears\n\n3.View the answer sheet again\n\n4.Re-Evaluate a answer sheet\n\n5.Check out\n>>", 0x75);
        __isoc99_scanf(&DAT_001020fe);
        putchar(10);
        switch (0x101af2) {
            case 0:
                puts("Sorry!!Wrong option choose from something that is in the menu");
                break;
            case 1:
                if (local_b8c < 0x1e) {
                    write(1, "Enter the size of the student record\n>>", 0x27);
                    read(0, local_38, 0x1f);
                    local_b88 = strtoul(local_38, (char **)0x0, 0);
                    if ((local_b88 == 0x268262) ||
                        (((0x17 < local_b88 && (local_b88 < 0x89)) && (local_b88 != 0)))) {
                        local_b80 = malloc(local_b88);
                        if (local_b80 == (void *)0x0) {
                            puts("Sorry can\'t retrieve the answer sheet");
                        } else {
                            write(1, "Enter the student\'s name\n>>", 0x1b);
                            read(0, local_b78 + (ulong)local_b8c * 0x60, 0x14);
                            write(1, "Enter the student\'s marks\n>>", 0x1c);
                            __isoc99_scanf(&DAT_001020fe, &local_b90);
                            if ((local_b90 < 0x28) || (100 < local_b90)) {
                                puts(
                                    "Students should be given pass marks which is between 40 and 100.If not falling back to 40");
                                (&iStack2916)[(ulong)local_b8c * 0x18] = 0x28;
                            } else {
                                (&iStack2916)[(ulong)local_b8c * 0x18] = local_b90;
                            }
                            write(1, "Enter the Remarks for the Students\n>>", 0x25);
                            read(0, acStack2912 + (ulong)local_b8c * 0x60, 0x38);
                            memset(local_b80, 0, 0x10);
                            (&pvStack2856)[(ulong)local_b8c * 0xc] = local_b80;
                            aiStack2848[(ulong)local_b8c * 0x18] = (int)local_b88;
                            write(1, "Enter something as a log for correcting this paper\n>>", 0x35);
                            read(0, (&pvStack2856)[(ulong)local_b8c * 0xc], (long)aiStack2848[(ulong)local_b8c * 0x18]);
                            local_b8c = local_b8c + 1;
                        }
                    } else {
                        puts("Sorry student record size should be only between 24 and 136");
                    }
                } else {
                    puts("Sorry No more answer sheets available");
                }
                break;
            case 2:
                write(1, "Enter the index number of the record\n>>", 0x27);
                __isoc99_scanf(&DAT_001020fe);
                if (((int)local_b94 < 0) || (0x1d < (int)local_b94)) {
                    puts("No integer bugs and index value greater than or equal to 30");
                } else {
                    if (((&pvStack2856)[(long)(int)local_b94 * 0xc] == (void *)0x0) || (local_b8c <= local_b94)) {
                        puts("Sorry to disappoint you but we don\'t entertain double arrears here");
                    }
                    else
                    {
                        free((&pvStack2856)[(long)(int)local_b94 * 0xc]);
                        (&pvStack2856)[(long)(int)local_b94 * 0xc] = (void *)0x0;
                        puts("Anna university to Students:Fun panrom");
                    }
                }
                break;
            case 3:
                write(1, "Enter the index number of the record you want to view\n>>", 0x38);
                __isoc99_scanf(&DAT_001020fe);
                if (((int)local_b94 < 0) || (0x1d < (int)local_b94)) {
                    puts("No integer bugs and index value greater than or equal to 30");
                } else {
                    if (((&pvStack2856)[(long)(int)local_b94 * 0xc] == (void *)0x0) || (local_b8c <= local_b94)) {
                        puts("Sorry we don\'t prefer Read after getting arrears");
                    } else {
                        write(1, "Here are the chunk contents\n", 0x1c);
                        write(1, (&pvStack2856)[(long)(int)local_b94 * 0xc],
                            (long)aiStack2848[(long)(int)local_b94 * 0x18]);
                    }
                }
                break;
            case 4:
                write(1, "Enter the index number of the record you want to edit\n>>", 0x38);
                __isoc99_scanf(&DAT_001020fe);
                if (((int)local_b94 < 0) || (0x1d < (int)local_b94)) {
                    puts("Sorry no integer bugs and index value greater than 30");
                } else {
                    if (((&pvStack2856)[(long)(int)local_b94 * 0xc] == (void *)0x0) || (local_b8c <= local_b94)) {
                        puts(
                            "Na Na Na!!!Sorry we don\'t allow you to write after you got arrears!!Wait for the upcoming semester");
                    } else {
                        write(1, "Enter the student\'s name\n>>", 0x1b);
                        read(0, local_b78 + (long)(int)local_b94 * 0x60, 0x14);
                        write(1, "Enter the student\'s marks\n>>", 0x1c);
                        __isoc99_scanf(&DAT_001020fe, &local_b90);
                        if ((local_b90 < 0x28) || (100 < local_b90)) {
                            puts(
                                "Students should be given pass marks which is between 40 and 100.If not falling back to 40");
                            (&iStack2916)[(long)(int)local_b94 * 0x18] = 0x28;
                        } else {
                            (&iStack2916)[(long)(int)local_b94 * 0x18] = local_b90;
                        }
                        local_b88 = strlen(acStack2912 + (long)(int)local_b94 * 0x60);
                        write(1, "Enter the Remarks for the Students\n>>", 0x25);
                        read(0, acStack2912 + (long)(int)local_b94 * 0x60, local_b88);
                        if ((void *)0x7effffffffff < (&pvStack2856)[(long)(int)local_b94 * 0xc]) {
                            puts("Sorry I can\'t let you change the answer contents to give pass marks");
                            exit(0);
                        }
                        write(1, "Enter new log for correcting this paper\n>>", 0x2a);
                        read(0, (&pvStack2856)[(long)(int)local_b94 * 0xc],
                            (long)aiStack2848[(long)(int)local_b94 * 0x18]);
                    }
                }
                break;
            case 5:
                puts("Thanks for spoiling most students life by putting arrears for getting revaluation money");
                exit(0);
        }
    } while (true);
}
