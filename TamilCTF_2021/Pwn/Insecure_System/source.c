// i 0x104018
undefined8 main(void) {
    vuln();
    return 0;
}

void vuln(void) {
    undefined local_38[40];
    undefined8 *local_10;

    sleep(2);
    printf("OOPS!!!!I AM LEAKING CRITICAL STUFF %p %p!!\nI am so Insecure!!!!\n", system, vuln);
    local_10 = &i;
    read(0, local_38, 0x30);
    putchar(10);
    __isoc99_scanf("%lu", local_10);
    return;
}
