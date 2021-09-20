// not 0x404180
// siz 0x404100
void main(void) {
    stkspace();
    _exit(0);
}

void invalid(undefined8 param_1) {
    printf("Invalid %s.\n", param_1);
    _exit(1);
}

void menu(long param_1) {
    int iVar1;
    int local_c;

    puts("Your options are:");
    puts("1) creat");
    puts("2) delet");
    puts("3) edit");
    puts("4) display");
    puts("5) exit\n");
    puts("What would you lik to do (enter option in format \"[number] go!\")?");
    local_c = 0;
    do {
        if (0x3fff < local_c) {
        LAB_004012b1:
            puts("");
            return;
        }
        iVar1 = getchar();
        *(char *)(param_1 + local_c) = (char)iVar1;
        *(undefined *)(param_1 + (long)local_c + 1) = 0;
        if (3 < local_c) {
            iVar1 = strcmp(" go!\n", (char *)(param_1 + (long)local_c + -4));
            if (iVar1 == 0) {
                *(undefined *)(param_1 + (long)local_c + -4) = 0;
                goto LAB_004012b1;
            }
        }
        local_c = local_c + 1;
    } while (true);
}

void stkspace(undefined8 param_1, __mode_t param_2) {
    char *__nptr;
    char local_38[44];
    int local_c;

    puts("Welcom to my heapnot challeng.");
    puts("I got a bit carried away...\n");
    local_c = 0;
    while (local_c != 5) {
        menu(local_38);
        __nptr = local_38;
        local_c = atoi(__nptr);
        switch (local_c) {
            default:
                invalid("option, does not exist");
                break;
            case 1:
                creat(__nptr, param_2);
                break;
            case 2:
                delet();
                break;
            case 3:
                edit();
                break;
            case 4:
                display();
                break;
            case 5:
                puts("Bye.");
        }
    }
    close(0);
    close(1);
    close(2);
    return;
}

int inidx(void) {
    int local_c;

    __isoc99_scanf("%d", &local_c);
    getchar();
    puts("");
    if ((local_c < 0) || (0x1f < local_c)) {
        invalid("index, out of bounds");
    }
    return local_c;
}

int creat(char *__file, __mode_t __mode) {
    int iVar1;
    void *pvVar2;

    puts("You get to creat a not.\n");
    puts("Which index would you lik to creat a not at?");
    iVar1 = inidx();
    if (*(long *)(not +(long)iVar1 * 8) != 0) {
        invalid("index, already exists");
    }
    puts("What siz would you lik your not to b?");
    __isoc99_scanf("%d", siz + (long)iVar1 * 4);
    getchar();
    puts("");
    if ((*(int *)(siz + (long)iVar1 * 4) < 1) || (0x1000 < *(int *)(siz + (long)iVar1 * 4))) {
        invalid("siz, out of bounds");
    }
    pvVar2 = malloc((long)(*(int *)(siz + (long)iVar1 * 4) + 1));
    *(void **)(not +(long)iVar1 * 8) = pvVar2;
    iVar1 = puts("Not created.\n");
    return iVar1;
}

void delet(void) {
    int iVar1;

    puts("You get to delet a not.\n");
    puts("Which index would you lik to delet a not from?");
    iVar1 = inidx();
    if (*(long *)(not +(long)iVar1 * 8) == 0) {
        invalid("index, does not exist");
    }
    freex(*(undefined8 *)(not +(long)iVar1 * 8));
    *(undefined8 *)(not +(long)iVar1 * 8) = 0;
    puts("Not deleted.\n");
    return;
}

void edit(void) {
    long lVar1;
    int iVar2;
    ssize_t sVar3;

    puts("You get to edit a not.\n");
    puts("Which index would you lik to edit a not at?");
    iVar2 = inidx();
    if (*(long *)(not +(long)iVar2 * 8) == 0) {
        invalid("index, doest not exist");
    }
    puts("What messag would you lik th not to contain?");
    lVar1 = *(long *)(not +(long)iVar2 * 8);
    sVar3 = read(0, *(void **)(not +(long)iVar2 * 8), (long)(*(int *)(siz + (long)iVar2 * 4) + 1));
    *(undefined *)(sVar3 + -1 + lVar1) = 0;
    puts("");
    puts("Not edited.\n");
    return;
}

void freex(void) {
    puts("This cod section is incomplet. W will work on finishing it soon.");
    _exit(1);
}

void display(void) {
    int iVar1;

    puts("You get to display a not.\n");
    puts("Which index would you lik to display a not from?");
    iVar1 = inidx();
    if (*(long *)(not +(long)iVar1 * 8) == 0) {
        invalid("index, does not exist");
    }
    printf("This not contains the messag: %s\n\n", *(undefined8 *)(not +(long)iVar1 * 8));
    puts("Not displayed.\n");
    return;
}
