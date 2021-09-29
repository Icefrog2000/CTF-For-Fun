
undefined8 main(void) {
    char *__format;
    long in_FS_OFFSET;
    char local_98[136];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    setbuf(stdout, (char *)0x0);
    setbuf(stderr, (char *)0x0);
    __format = (char *)malloc(0x80);
    puts("Oh no! Evil Morty is attempting to open the central finite curve!");
    puts("You get three inputs to try to stop him.\n");
    puts("Input 1:");
    read(0, local_98, 0xb0);
    puts(local_98);
    puts("Input 2:");
    read(0, local_98, 0x80);
    puts("\nInput 3:");
    read(0, __format, 0x80);
    printf(__format);
    free(__format);
    puts("\nLol how could inputting strings stop the central finite curve.");
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        __stack_chk_fail();
    }
    return 0;
}
