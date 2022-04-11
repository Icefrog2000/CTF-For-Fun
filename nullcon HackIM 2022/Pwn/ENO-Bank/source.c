#include <stdio.h>
#include <stdlib.h>

// 0x101802
void menu(void) {
    puts("");
    puts("1: Create new account");
    puts("2: Delete account");
    puts("3: View account");
    puts("4: Get a loan");
    puts("5: Transfer money");
    puts("6: Exit");
    printf("=> ");
    return;
}

// 0x10131b
void read_long(void) {
    long in_FS_OFFSET;
    char *local_40;
    char local_38[40];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    fgets(local_38, 0x20, stdin);
    strtoul(local_38, &local_40, 10);
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return;
}

// 0x101872
undefined8 main(void) {
    int local_c;

    puts("Welcome to the ENO-Bank!");
    local_c = -1;
    while (local_c != 6) {
        menu();
        local_c = read_long();
        switch (local_c)
        {
        default:
            puts("Invalid choice");
            break;
        case 1:
            create();
            break;
        case 2:
            delete();
            break;
        case 3:
            view();
            break;
        case 4:
            get_a_loan();
            break;
        case 5:
            transfer_money();
        }
    }
    return 0;
}

// 0x1012b0
unsigned int FUN_001012b0(void) {
    unsigned int local_c;

    local_c = 0;
    while (1) {
        if (6 < local_c) {
            return 0xffffffff;
        }
        if (*(long *)(&DAT_00104060 + (long)(int)local_c * 8) == 0)
            break;
        if ((*(unsigned long *)(&DAT_00104060 + (long)(int)local_c * 8) & 1) != 0)
        {
            return local_c;
        }
        local_c = local_c + 1;
    }
    return local_c;
}

// 0x10137c
void create(void) {
    unsigned int uVar1;
    undefined8 *__ptr;
    ssize_t sVar2;

    uVar1 = FUN_001012b0();
    if ((int)uVar1 < 0) {
        puts("Max amount of accounts reached");
    }
    else {
        __ptr = (undefined8 *)malloc(0x108);
        if (__ptr != (undefined8 *)0x0) {
            puts("Enter a name for your account: ");
            sVar2 = read(0, __ptr + 1, 0x100);
            if ((int)sVar2 < 0) {
                free(__ptr);
                perror("read");
            }
            else
            {
                *(undefined *)((long)__ptr + 0x107) = 0;
                *__ptr = 0;
                *(undefined8 **)(&DAT_00104060 + (long)(int)uVar1 * 8) = __ptr;
                printf("New account created with id %d \n", (unsigned long)uVar1);
            }
        }
    }
    return;
}

// 0x101462
void delete(void) {
    void *__ptr;
    unsigned int uVar1;

    printf("Enter id of account you want to delete: ");
    uVar1 = read_long();
    if (uVar1 < 7) {
        __ptr = *(void **)(&DAT_00104060 + (unsigned long)uVar1 * 8);
        if ((__ptr == (void *)0x0) || (((unsigned long)__ptr & 1) != 0)) {
            puts("Account doesn\'t exist");
        }
        else {
            *(unsigned long *)(&DAT_00104060 + (unsigned long)uVar1 * 8) = (unsigned long)__ptr ^ 1;
            free(__ptr);
            printf("Account with id %d deleted \n", (unsigned long)uVar1);
        }
    }
    else {
        puts("Invalid index");
    }
    return;
}

// 0x101525
void view(void) {
    undefined8 *puVar1;
    unsigned int uVar2;

    printf("Enter the id of account you want to view: ");
    uVar2 = read_long();
    if (uVar2 < 7) {
        puVar1 = *(undefined8 **)(&DAT_00104060 + (unsigned long)uVar2 * 8);
        if ((puVar1 == (undefined8 *)0x0) || (((unsigned long)puVar1 & 1) != 0)) {
            puts("Account doesn\'t exist!");
        }
        else {
            printf("Name: %s, Balance: %ld \n", puVar1 + 1, *puVar1);
        }
    }
    else
    {
        puts("Invalid index");
    }
    return;
}

// 0x10172d
void get_a_loan(void) {
    long *plVar1;
    int iVar2;
    unsigned int uVar3;

    printf("Enter the amount you would like to borrow: ");
    iVar2 = read_long();
    if (iVar2 < 0x1338) {
        printf("Id of account to receive loan: ");
        uVar3 = read_long();
        if (uVar3 < 7) {
            plVar1 = *(long **)(&DAT_00104060 + (unsigned long)uVar3 * 8);
            if ((plVar1 == (long *)0x0) || (((unsigned long)plVar1 & 1) != 0)) {
                puts("Account doesn\'t exist!");
            }
            else {
                *plVar1 = *plVar1 + (long)iVar2;
                puts("Loan has been given");
            }
        }
        else {
            puts("Invalid index");
        }
    }
    else {
        puts("Amount too big!");
    }
    return;
}

// 0x1015ce
void transfer_money(void) {
    unsigned long *puVar1;
    long *plVar2;
    unsigned long uVar3;
    unsigned long uVar4;
    unsigned long uVar5;

    printf("Enter id of account you want to send money from: ");
    uVar3 = read_long();
    printf("Enter id of account you want to send the money to: ");
    uVar4 = read_long();
    printf("amount: ");
    uVar5 = read_long();
    if (uVar4 == uVar3)
    {
        puts("Can\'t send money to yourself");
    }
    else if ((uVar3 < 7) && (uVar4 < 7)) {
        puVar1 = *(unsigned long **)(&DAT_00104060 + uVar3 * 8);
        plVar2 = *(long **)(&DAT_00104060 + uVar4 * 8);
        if (((puVar1 == (unsigned long *)0x0) || (((unsigned long)puVar1 & 1) != 0)) || (plVar2 == (long *)0x0)) {
            puts("Account doesn\'t exist");
        }
        else if (*puVar1 < uVar5) {
            puts("Insufficient funds to transfer amount!");
        }
        else {
            *plVar2 = uVar5 + *plVar2;
            *puVar1 = *puVar1 - uVar5;
            puts("Money transferred");
        }
    }
    else {
        puts("Invalid index");
    }
    return;
}