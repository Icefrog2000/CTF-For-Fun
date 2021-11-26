#include <stdio.h>
#include <pthread.h>

typedef struct robot {
    char* func1;
    int donum_or_dostring;
    int type;
    char* st2;
    long st3;
    char* stack;
    long length1;
    long length2;
    long done;
} Robot;

Robot* robots[8]; // 0x4040c0

void self_destruct_protocol(void) {
    int local_c;
    do {
        for (local_c = 0; local_c < 8; local_c = local_c + 1) {
            if ((*(long *)(robots + (long)local_c * 8) != 0) &&
                (*(char *)(*(long *)(robots + (long)local_c * 8) + 0x38) != '\0')) {
                if (*(int *)(*(long *)(robots + (long)local_c * 8) + 8) == 0) {
                    printf("Result: %ld", *(long *)(*(long *)(robots + (long)local_c * 8) + 0x20));
                }
                else {
                    if (*(int *)(*(long *)(robots + (long)local_c * 8) + 8) == 1) {
                        printf("Result: %s", *(long *)(*(long *)(robots + (long)local_c * 8) + 0x20));
                    }
                }
                write(1, '\n', 2);
                free(*(void **)(robots + (long)local_c * 8));
                *(long *)(robots + (long)local_c * 8) = 0;
            }
        }
        sleep(1);
    } while (1);
}

void main(void) {
    pthread_t local_10;

    setvbuf(stdout, (char *)0x0, 2, 0);
    puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    puts("|                                 |");
    puts("|  WELCOME TO THE ROBOT FACTORY!  |");
    puts("|    DAYS WITHOUT AN ACCIDENT:    |");
    puts("|               0                 |");
    puts("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    pthread_create(&local_10, (pthread_attr_t *)0x0, self_destruct_protocol, (void *)0x0);
    do {
        create_robot();
    } while (1);
}

void create_robot(void) {
    long lVar1;
    char cVar2;
    char cVar3;
    int iVar4;
    void *pvVar5;
    int local_30;
    int local_2c;
    pthread_t local_28;
    long length;

    local_30 = -1;
    for (local_2c = 0; local_2c < 8; local_2c = local_2c + 1) {
        if (*(long *)(robots + (long)local_2c * 8) == 0) {
            local_30 = local_2c;
            break;
        }
    }
    if (local_30 == -1) {
        puts("Error! No free parts!");
    }
    else {
        pvVar5 = malloc(0x40);
        *(void **)(robots[local_30]) = pvVar5;
        *(char *)(*(long *)(robots[local_30]) + 0x38) = 0;
        do {
            printf("What kind of robot would you like? (n/s) > ");
            iVar4 = getchar();
            cVar2 = (char)iVar4;
            getchar();
            if (cVar2 == 'n')
                break;
        } while (cVar2 != 's');
        do {
            printf("What kind of operation do you want? (a/s/m) > ");
            iVar4 = getchar();
            cVar3 = (char)iVar4;
            getchar();
            if ((cVar3 == 'a') || (cVar3 == 's'))
                break;
        } while (cVar3 != 'm');
        if (cVar2 == 's') {
            *(int *)(*(long *)(robots[local_30]) + 8) = 1;
            printf("Enter string 1: ");
            lVar1 = *(long *)(robots[local_30]);
            pvVar5 = malloc(0x100);
            *(void **)(lVar1 + 0x10) = pvVar5;
            fgets(*(char **)(*(long *)(robots[local_30]) + 0x10), 0x100, stdin);
            pvVar5 = memchr(*(void **)(*(long *)(robots[local_30]) + 0x10), 10, 0x100);
            length = (long)pvVar5 - *(long *)(*(long *)(robots[local_30]) + 0x10);
            *(long *)(*(long *)(robots[local_30]) + 0x28) = length;
            if (cVar3 == 'a') {
                printf("Enter string 2: ");
                lVar1 = *(long *)(robots[local_30]);
                pvVar5 = malloc(0x100);
                *(void **)(lVar1 + 0x18) = pvVar5;
                fgets(*(char **)(*(long *)(robots[local_30]) + 0x18), 0x100, stdin);
                pvVar5 = memchr( *(void **)(*(long *)(robots[local_30]) + 0x18), 10, 0x100);
                length = (long)pvVar5 - *(long *)(*(long *)(robots[local_30]) + 0x18);
                *(long *)(*(long *)(robots[local_30]) + 0x30) = length;
            }
            else {
                if (cVar3 != 'm') {
                    puts("NOT IMPLEMENTED");
                    free(*(void **)(robots[local_30]));
                    return;
                }
                printf("Enter size: ");
                __isoc99_scanf("%ld", *(long *)(robots[local_30]) + 0x18);
                getchar();
            }
        }
        else {
            if (cVar2 == 'n') {
                *(int *)(*(long *)(robots[local_30]) + 8) = 0;
                printf("Enter number 1: ");
                __isoc99_scanf("%ld", *(long *)(robots[local_30]) + 0x10);
                getchar();
                printf("Enter number 2: ");
                __isoc99_scanf("%ld", *(long *)(robots[local_30]) + 0x18);
                getchar();
            }
        }
        if (cVar3 == 's') {
            *(int *)(*(long *)(robots[local_30]) + 0xc) = 1;
        }
        else {
            if (cVar3 < 't') {
                if (cVar3 == 'a') {
                    *(int *)(*(long *)(robots[local_30]) + 0xc) = 0;
                }
                else {
                    if (cVar3 == 'm') {
                        *(int *)(*(long *)(robots[local_30]) + 0xc) = 2;
                    }
                }
            }
        }
        pthread_create(&local_28, (pthread_attr_t *)0x0, do_robot,
                       *(void **)(robots[local_30]));
        **(pthread_t **)(robots[local_30]) = local_28;
    }
    return;
}

void add_func(long param_1) {
    if (*(int *)(param_1 + 8) == 0) {
        **(long **)(param_1 + 0x20) = *(long *)(param_1 + 0x18) + *(long *)(param_1 + 0x10);
    }
    else {
        if (*(int *)(param_1 + 8) == 1) {
            memcpy(*(void **)(param_1 + 0x20), *(void **)(param_1 + 0x10), *(size_t *)(param_1 + 0x28));
            memcpy(
                (void *)(*(long *)(param_1 + 0x20) + *(long *)(param_1 + 0x28)),
                *(void **)(param_1 + 0x18), *(size_t *)(param_1 + 0x30));
            free(*(void **)(param_1 + 0x10));
            free(*(void **)(param_1 + 0x18));
        }
    }
    return;
}

void multiply_func(long param_1) {
    long local_18;
    long local_10;

    if (*(int *)(param_1 + 8) == 0) {
        **(long **)(param_1 + 0x20) = *(long *)(param_1 + 0x18) * *(long *)(param_1 + 0x10);
    }
    else {
        if (*(int *)(param_1 + 8) == 1) {
            memcpy(*(void **)(param_1 + 0x20), *(void **)(param_1 + 0x10), *(size_t *)(param_1 + 0x28));
            local_10 = *(long *)(param_1 + 0x28);
            for (local_18 = 0; local_18 < *(long *)(param_1 + 0x18); local_18++) {
                memcpy((void *)(*(long *)(param_1 + 0x20) + local_10), *(void **)(param_1 + 0x10), *(size_t *)(param_1 + 0x28));
                local_10 = local_10 + *(long *)(param_1 + 0x28);
            }
        }
    }
    return;
}

void do_num(long param_1) {
    unsigned int uVar1;
    char local_10[8];

    *(char **)(param_1 + 0x20) = local_10;
    uVar1 = *(unsigned int *)(param_1 + 0xc);
    if (uVar1 == 2) {
        multiply_func(param_1);
    }
    else {
        if (uVar1 < 3) {
            if (uVar1 == 0) {
                add_func(param_1);
            }
            else {
                if (uVar1 == 1) {
                    sub_func(param_1);
                }
            }
        }
    }
    *(char *)(param_1 + 0x38) = 1;
    return;
}

void do_string(long param_1) {
    long in_FS_OFFSET;
    char local_118[264];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    *(char **)(param_1 + 0x20) = local_118;
    if (*(int *)(param_1 + 0xc) == 0) {
        add_func(param_1);
    }
    else {
        if (*(int *)(param_1 + 0xc) == 2) {
            multiply_func(param_1);
        }
    }
    *(char *)(param_1 + 0x38) = 1;
    if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
        return;
    }
    __stack_chk_fail();
}

void do_robot(long param_1) {
    if (*(int *)(param_1 + 8) == 0) {
        do_num(param_1);
    }
    else {
        if (*(int *)(param_1 + 8) == 1) {
            do_string(param_1);
        }
    }
    return;
}

void sub_func(long param_1) {
    if (*(int *)(param_1 + 8) == 0) {
        **(long **)(param_1 + 0x20) = *(long *)(param_1 + 0x10) - *(long *)(param_1 + 0x18);
    }
    else {
        if (*(int *)(param_1 + 8) == 1) {
            do {
                invalidInstructionException();
            } while (1);
        }
    }
    return;
}