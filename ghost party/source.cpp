undefined8 FUN_001039ad(void) {
    undefined8 *puVar1;
    long lVar2;
    undefined8 uVar3;
    undefined8 uVar4;
    char cVar5;
    int iVar6;
    int iVar7;
    undefined *puVar8;
    undefined *__dest;
    long *plVar9;
    ulong uVar10;
    undefined **ppuVar11;
    char *pcVar12;
    long *plVar13;
    long lVar14;
    undefined8 uVar15;
    char *pcVar16;
    long in_FS_OFFSET;
    byte bVar17;
    undefined4 local_5e4;
    int age;
    int local_5dc;
    char *point_to_name;
    undefined8 size_of_name;
    char local_5c8[16];
    char *message;
    undefined8 local_5b0;
    char local_5a8[16];
    char *local_598;
    long local_590;
    char local_588[16];
    undefined *local_578[2];
    undefined local_568[16];
    char *local_558;
    long local_550;
    char local_548[16];
    undefined *local_538[2];
    undefined local_528[16];
    undefined *local_518;
    size_t local_510;
    undefined local_508[16];
    char *local_4f8;
    long local_4f0;
    char local_4e8[16];
    undefined *local_4d8[2];
    undefined local_4c8[16];
    char *local_4b8;
    size_t local_4b0;
    char local_4a8[16];
    undefined *local_498[2];
    undefined local_488[16];
    undefined *local_478;
    size_t local_470;
    undefined local_468[16];
    undefined *local_458[2];
    undefined local_448[16];
    undefined *local_438[2];
    undefined local_428[16];
    char *local_418;
    long local_410;
    char local_408[16];
    undefined *local_3f8[2];
    undefined local_3e8[16];
    undefined *local_3d8[2];
    undefined local_3c8[16];
    char *local_3b8;
    long local_3b0;
    char local_3a8[16];
    undefined *local_398[2];
    undefined local_388[16];
    undefined *local_378;
    size_t local_370;
    undefined local_368[16];
    char *local_358;
    long local_350;
    char local_348[16];
    undefined *local_338[2];
    undefined local_328[16];
    undefined *local_318[2];
    undefined local_308[16];
    char *local_2f8;
    long local_2f0;
    char local_2e8[16];
    undefined *local_2d8[2];
    undefined local_2c8[16];
    undefined *local_2b8[2];
    undefined local_2a8[16];
    char *local_298;
    long local_290;
    char local_288[16];
    undefined *local_278[2];
    undefined local_268[16];
    char *local_258;
    undefined8 local_250;
    char local_248[16];
    undefined8 *local_238[2];
    undefined8 local_228;
    code *local_220;
    undefined8 local_218;
    undefined8 local_210;
    undefined8 local_208;
    undefined8 local_200;
    undefined8 local_1f8;
    undefined8 local_1f0;
    locale local_1e8[8];
    undefined4 local_1e0;
    undefined *local_1d8;
    undefined8 local_1d0;
    undefined local_1c8[16];
    code *local_1b8[27];
    undefined8 local_e0;
    undefined local_d8;
    undefined local_d7;
    undefined8 local_d0;
    undefined8 local_c8;
    undefined8 local_c0;
    undefined8 local_b8;
    char local_a8[32];
    undefined8 local_88;
    undefined8 local_80;
    undefined8 local_78;
    undefined8 local_70;
    undefined8 local_68;
    undefined8 local_60;
    undefined8 local_58;
    undefined8 local_50;
    long local_40;

    bVar17 = 0;
    local_40 = *(long *)(in_FS_OFFSET + 0x28);
    point_to_name = local_5c8;
    size_of_name = 0;
    local_5c8[0] = '\0';
    message = local_5a8;
    local_5b0 = 0;
    local_5a8[0] = '\0';
    /* try { // try from 00103a23 to 00103b62 has its CatchHandler @ 00106264 */
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Name : ", 7);
    std::operator>>((basic_istream *)&std::cin, (basic_string *)&point_to_name);
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Age : ", 6);
    std::basic_istream<char, std::char_traits<char>>::operator>>((basic_istream<char, std::char_traits<char>> *)&std::cin, &age);
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Message : ", 10);
    std::basic_istream<char, std::char_traits<char>>::ignore();
    plVar13 = *(long **)(&__cxxabiv1::__class_type_info::vtable + *(long *)(std::cin + -0x18));
    if (plVar13 == (long *)0x0)
    {
        std::__throw_bad_cast();
    }
    if (*(char *)(plVar13 + 7) == '\0')
    {
        std::ctype<char>::_M_widen_init();
        cVar5 = (**(code **)(*plVar13 + 0x30))(plVar13, 10);
    }
    else
    {
        cVar5 = *(char *)((long)plVar13 + 0x43);
    }
    std::getline<char, std::char_traits<char>, std::allocator<char>>((basic_istream *)&std::cin, (basic_string *)&message, cVar5);
    typelist();
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Choose a type of ghost :", 0x18);
    std::basic_istream<char, std::char_traits<char>>::_M_extract<unsigned_int>((uint *)&std::cin);
    iVar6 = (int)point_to_name;
    iVar7 = (int)size_of_name;
    switch (local_5e4)
    {
    default:
        /* try { // try from 00105d3c to 00105d99 has its CatchHandler @ 00106264 */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[31mInvaild choice\x1b[0m", 0x17);
        plVar13 = *(long **)(&std::__cxx11::
                                 basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                             *(long *)(std::cout + -0x18));
        if (plVar13 == (long *)0x0)
        {
            std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        std::basic_ostream<char, std::char_traits<char>>::put(-8);
        std::basic_ostream<char, std::char_traits<char>>::flush();
        uVar15 = 0;
        break;
    case 1:
        local_598 = local_588;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_598, point_to_name, iVar6 + iVar7);
        local_578[0] = local_568;
        /* try { // try from 00103b8a to 00103b8e has its CatchHandler @ 00105e1a */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_578, message, (int)message + (int)local_5b0);
        /* try { // try from 00103b98 to 00103b9c has its CatchHandler @ 00105dfd */
        ppuVar11 = (undefined **)operator.new(0x60);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 00103c0d to 00103c11 has its CatchHandler @ 00103c40 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_00310b98;
        /* try { // try from 00103c39 to 00103ca0 has its CatchHandler @ 00103cbd */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong) "Werewolf");
        *(int *)(ppuVar11 + 1) = age;
        pcVar12 = (char *)operator.new[](local_590 + 1);
        ppuVar11[2] = pcVar12;
        strcpy(pcVar12, local_598);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        *(undefined4 *)(ppuVar11 + 0xb) = 0;
        if (local_578[0] != local_568)
        {
            operator.delete(local_578[0]);
        }
        if (local_598 != local_588)
        {
            operator.delete(local_598);
        }
        /* try { // try from 00103cfd to 00103d48 has its CatchHandler @ 00106264 */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Full moon ? (1:yes/0:no):", 0x19);
        std::basic_istream<char, std::char_traits<char>>::operator>>((basic_istream<char, std::char_traits<char>> *)&std::cin, &local_5dc);
        *(int *)(ppuVar11 + 0xb) = local_5dc;
        if (local_5dc == 1) {
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 7), 0, ppuVar11[8], (ulong) "Wow Wow Wowwwwwwwww");
        }
        FUN_0010b105(ppuVar11);
        uVar15 = 1;
        break;
    case 2:
        local_258 = local_248;
        local_250 = 0;
        local_248[0] = '\0';
        local_558 = local_548;
        /* try { // try from 00103d9c to 00103da0 has its CatchHandler @ 00105ea2 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_558, point_to_name, iVar6 + iVar7);
        local_538[0] = local_528;
        /* try { // try from 00103dc8 to 00103dcc has its CatchHandler @ 00105e68 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_538, message, (int)message + (int)local_5b0);
        /* try { // try from 00103dd6 to 00103dda has its CatchHandler @ 00105e4b */
        ppuVar11 = (undefined **)operator.new(0x60);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 00103e4b to 00103e4f has its CatchHandler @ 00103e7e */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_00310b60;
        /* try { // try from 00103e77 to 00103ed8 has its CatchHandler @ 00103ef6 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong) "Devil");
        *(int *)(ppuVar11 + 1) = age;
        pcVar12 = (char *)operator.new[](local_550 + 1);
        ppuVar11[2] = pcVar12;
        strcpy(pcVar12, local_558);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        ppuVar11[0xb] = (undefined *)0x0;
        if (local_538[0] != local_528)
        {
            operator.delete(local_538[0]);
        }
        if (local_558 != local_548)
        {
            operator.delete(local_558);
        }
        /* try { // try from 00103f36 to 00103fcf has its CatchHandler @ 00105ea2 */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Add power : ", 0xc);
        std::basic_istream<char, std::char_traits<char>>::ignore();
        plVar13 = *(long **)(&__cxxabiv1::__class_type_info::vtable + *(long *)(std::cin + -0x18));
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            cVar5 = (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        else
        {
            cVar5 = *(char *)((long)plVar13 + 0x43);
        }
        std::getline<char, std::char_traits<char>, std::allocator<char>>((basic_istream *)&std::cin, (basic_string *)&local_258, cVar5);
        local_518 = local_508;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_518, local_258, (int)local_258 + (int)local_250);
        std::ios_base::ios_base((ios_base *)local_1b8);
        uVar15 = _memcpy;
        puVar1 = _put;
        local_1b8[0] = std::ios_base::ios_base;
        local_e0 = 0;
        local_d8 = 0;
        local_d7 = 0;
        local_d0 = 0;
        local_c8 = 0;
        local_c0 = 0;
        local_b8 = 0;
        local_238[0] = _put;
        *(undefined8 *)((long)local_238 + _put[-3]) = _memcpy;
        local_238[1] = (undefined8 *)0x0;
        /* try { // try from 00104082 to 00104086 has its CatchHandler @ 00104298 */
        std::basic_ios<char, std::char_traits<char>>::init((basic_streambuf *)((long)local_238 + local_238[0][-3]));
        uVar3 = _open;
        lVar2 = _ ~basic_stringstream;
        local_228 = (undefined *)_ ~basic_stringstream;
        *(undefined8 *)((long)&local_228 + *(long *)(_ ~basic_stringstream + -0x18)) = _open;
        /* try { // try from 001040cb to 001040cf has its CatchHandler @ 001041e7 */
        std::basic_ios<char, std::char_traits<char>>::init((basic_streambuf *)((long)&local_228 + *(long *)((long)local_228 + -0x18)));
        uVar4 = stdout;
        lVar14 = _ ~locale;
        *(undefined8 *)((long)local_238 + *(long *)(_ ~locale + -0x18)) = stdout;
        local_238[0] = (undefined8 *)std::__throw_bad_cast;
        local_1b8[0] = exit;
        local_228 = &std::__cxx11::basic_stringbuf<char, std::char_traits<char>, std::allocator<char>>::
                        vtable;
        local_220 = std::__throw_bad_alloc;
        local_218 = 0;
        local_210 = 0;
        local_208 = 0;
        local_200 = 0;
        local_1f8 = 0;
        local_1f0 = 0;
        std::locale::locale(local_1e8);
        local_220 = _Jv_RegisterClasses;
        local_1e0 = 0x18;
        local_1d8 = local_1c8;
        local_1d0 = 0;
        local_1c8[0] = 0;
        /* try { // try from 001041dd to 001041e1 has its CatchHandler @ 00104203 */
        std::basic_ios<char, std::char_traits<char>>::init((basic_streambuf *)local_1b8);
        /* try { // try from 001042c9 to 001043c9 has its CatchHandler @ 001044c7 */
        pcVar12 = (char *)operator.new[](local_510 + 1);
        ppuVar11[0xb] = pcVar12;
        memcpy(pcVar12, local_518, local_510);
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Your power : ", 0xd);
        if (pcVar12 == (char *)0x0)
        {
            std::basic_ios<char, std::char_traits<char>>::clear((int)*(undefined8 *)(std::cout + -0x18) + 0x3120f8);
        }
        else
        {
            uVar10 = 0xffffffffffffffff;
            pcVar16 = pcVar12;
            do
            {
                if (uVar10 == 0)
                    break;
                uVar10 = uVar10 - 1;
                cVar5 = *pcVar16;
                pcVar16 = pcVar16 + (ulong)bVar17 * -2 + 1;
            } while (cVar5 != '\0');
            std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, pcVar12, ~uVar10 - 1);
        }
        plVar13 = *(long **)(&std::__cxx11::
                                 basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                             *(long *)(std::cout + -0x18));
        if (plVar13 == (long *)0x0)
        {
            std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        std::basic_ostream<char, std::char_traits<char>>::put(-8);
        std::basic_ostream<char, std::char_traits<char>>::flush();
        local_238[0] = (undefined8 *)std::__throw_bad_cast;
        local_1b8[0] = exit;
        local_228 = &std::__cxx11::basic_stringbuf<char, std::char_traits<char>, std::allocator<char>>::
                        vtable;
        local_220 = _Jv_RegisterClasses;
        if (local_1d8 != local_1c8)
        {
            operator.delete(local_1d8);
        }
        local_220 = std::__throw_bad_alloc;
        std::locale::~locale(local_1e8);
        *(undefined8 *)((long)local_238 + *(long *)(lVar14 + -0x18)) = uVar4;
        local_228 = (undefined *)lVar2;
        *(undefined8 *)((long)&local_228 + *(long *)(lVar2 + -0x18)) = uVar3;
        local_238[0] = puVar1;
        *(undefined8 *)((long)local_238 + puVar1[-3]) = uVar15;
        local_1b8[0] = std::ios_base::ios_base;
        /* try { // try from 001044ad to 001044b1 has its CatchHandler @ 00105e85 */
        std::ios_base::~ios_base((ios_base *)local_1b8);
        if (local_518 != local_508)
        {
            operator.delete(local_518);
        }
        /* try { // try from 001044e3 to 001044e7 has its CatchHandler @ 00105ea2 */
        FUN_0010a457(ppuVar11);
        if (local_258 != local_248)
        {
            operator.delete(local_258);
        }
        uVar15 = 1;
        break;
    case 3:
        local_4f8 = local_4e8;
        /* try { // try from 00104533 to 00104537 has its CatchHandler @ 00106264 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_4f8, point_to_name, iVar6 + iVar7);
        local_4d8[0] = local_4c8;
        /* try { // try from 0010455f to 00104563 has its CatchHandler @ 00105eed */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_4d8, message, (int)message + (int)local_5b0);
        /* try { // try from 0010456d to 00104571 has its CatchHandler @ 00105ed0 */
        ppuVar11 = (undefined **)operator.new(0x60);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 001045e2 to 001045e6 has its CatchHandler @ 00104615 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_00310bd0;
        /* try { // try from 0010460e to 00104673 has its CatchHandler @ 00104691 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong) "Zombie");
        *(int *)(ppuVar11 + 1) = age;
        pcVar12 = (char *)operator.new[](local_4f0 + 1);
        ppuVar11[2] = pcVar12;
        strcpy(pcVar12, local_4f8);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        ppuVar11[0xb] = (undefined *)0x0;
        if (local_4d8[0] != local_4c8)
        {
            operator.delete(local_4d8[0]);
        }
        if (local_4f8 != local_4e8)
        {
            operator.delete(local_4f8);
        }
        /* try { // try from 001046c3 to 0010480d has its CatchHandler @ 00106264 */
        puVar8 = (undefined *)operator.new[](0x41);
        ppuVar11[0xb] = puVar8;
        iVar6 = open("/dev/urandom", 0);
        iVar7 = open("/home/flags/ghostparty", 0);
        if ((iVar6 != -1) && (iVar7 != -1))
        {
            read(iVar6, &local_88, 0x20);
            read(iVar7, &local_68, 0x20);
            lVar14 = 0;
            do
            {
                __sprintf_chk(ppuVar11[0xb] + lVar14 * 2, 1, 0xffffffffffffffff, &DAT_0010e1e7,
                              *(byte *)((long)&local_88 + lVar14) ^ *(byte *)((long)&local_68 + lVar14));
                lVar14 = lVar14 + 1;
            } while (lVar14 != 0x20);
            lseek(iVar7, 0, 0);
            local_68 = 0;
            local_60 = 0;
            local_58 = 0;
            local_50 = 0;
            local_88 = 0;
            local_80 = 0;
            local_78 = 0;
            local_70 = 0;
            close(iVar6);
        }
        FUN_00109dc9(ppuVar11);
        uVar15 = 1;
        break;
    case 4:
        local_4b8 = local_4a8;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_4b8, point_to_name, iVar6 + iVar7);
        local_498[0] = local_488;
        /* try { // try from 00104835 to 00104839 has its CatchHandler @ 00105f3b */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_498, message, (int)message + (int)local_5b0);
        /* try { // try from 00104843 to 00104847 has its CatchHandler @ 00105f1e */
        ppuVar11 = (undefined **)operator.new(0x60);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 001048b8 to 001048bc has its CatchHandler @ 001048eb */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_00310a80;
        /* try { // try from 001048e4 to 0010494c has its CatchHandler @ 00104969 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong) "Skull");
        *(int *)(ppuVar11 + 1) = age;
        pcVar12 = (char *)operator.new[](local_4b0 + 1);
        ppuVar11[2] = pcVar12;
        strncpy(pcVar12, local_4b8, local_4b0);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        *(undefined4 *)(ppuVar11 + 0xb) = 0;
        if (local_498[0] != local_488)
        {
            operator.delete(local_498[0]);
        }
        if (local_4b8 != local_4a8)
        {
            operator.delete(local_4b8);
        }
        /* try { // try from 001049a9 to 001049d1 has its CatchHandler @ 00106264 */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "How many bones ? : ", 0x13);
        std::basic_istream<char, std::char_traits<char>>::operator>>((basic_istream<char, std::char_traits<char>> *)&std::cin, &local_5dc);
        *(int *)(ppuVar11 + 0xb) = local_5dc;
        FUN_0010bd7e(ppuVar11);
        uVar15 = 1;
        break;
    case 5:
        local_238[0] = &local_228;
        local_238[1] = (undefined8 *)0x0;
        local_228 = (undefined *)((ulong)local_228._1_7_ << 8);
        local_478 = local_468;
        /* try { // try from 00104a25 to 00104a29 has its CatchHandler @ 00105fc3 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_478, point_to_name, iVar6 + iVar7);
        local_458[0] = local_448;
        /* try { // try from 00104a51 to 00104a55 has its CatchHandler @ 00105f89 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_458, message, (int)message + (int)local_5b0);
        /* try { // try from 00104a5f to 00104a63 has its CatchHandler @ 00105f6c */
        ppuVar11 = (undefined **)operator.new(0x78);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 00104ad4 to 00104ad8 has its CatchHandler @ 00104b1b */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_00310a10;
        ppuVar11[0xb] = (undefined *)(ppuVar11 + 0xd);
        ppuVar11[0xc] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 0xd) = 0;
        /* try { // try from 00104b14 to 00104b7c has its CatchHandler @ 00104b7f */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong) "Mummy");
        *(int *)(ppuVar11 + 1) = age;
        puVar8 = (undefined *)operator.new[](local_470 + 1);
        ppuVar11[2] = puVar8;
        memcpy(puVar8, local_478, local_470);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        if (local_458[0] != local_448)
        {
            operator.delete(local_458[0]);
        }
        if (local_478 != local_468)
        {
            operator.delete(local_478);
        }
        /* try { // try from 00104be0 to 00104c79 has its CatchHandler @ 00105fc3 */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Commit on bandage : ", 0x14);
        std::basic_istream<char, std::char_traits<char>>::ignore();
        plVar13 = *(long **)(&__cxxabiv1::__class_type_info::vtable + *(long *)(std::cin + -0x18));
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            cVar5 = (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        else
        {
            cVar5 = *(char *)((long)plVar13 + 0x43);
        }
        std::getline<char, std::char_traits<char>, std::allocator<char>>((basic_istream *)&std::cin, (basic_string *)local_238, cVar5);
        local_438[0] = local_428;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_438, (char *)local_238[0], (int)local_238[0] + (int)local_238[1]);
        /* try { // try from 00104c89 to 00104c8d has its CatchHandler @ 00105fa6 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 0xb));
        if (local_438[0] != local_428)
        {
            operator.delete(local_438[0]);
        }
        /* try { // try from 00104ca9 to 00104cad has its CatchHandler @ 00105fc3 */
        FUN_0010c44f(ppuVar11);
        if (local_238[0] != &local_228)
        {
            operator.delete(local_238[0]);
        }
        uVar15 = 1;
        break;
    case 6:
        local_238[0] = &local_228;
        local_238[1] = (undefined8 *)0x0;
        local_228 = (undefined *)((ulong)local_228._1_7_ << 8);
        local_418 = local_408;
        /* try { // try from 00104d19 to 00104d1d has its CatchHandler @ 0010604b */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_418, point_to_name, iVar6 + iVar7);
        local_3f8[0] = local_3e8;
        /* try { // try from 00104d45 to 00104d49 has its CatchHandler @ 00106011 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_3f8, message, (int)message + (int)local_5b0);
        /* try { // try from 00104d53 to 00104d57 has its CatchHandler @ 00105ff4 */
        ppuVar11 = (undefined **)operator.new(0x78);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 00104dc8 to 00104dcc has its CatchHandler @ 00104e0f */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_00310a48;
        ppuVar11[0xb] = (undefined *)(ppuVar11 + 0xd);
        ppuVar11[0xc] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 0xd) = 0;
        /* try { // try from 00104e08 to 00104e69 has its CatchHandler @ 00104e6c */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong) "Dullahan");
        *(int *)(ppuVar11 + 1) = age;
        pcVar12 = (char *)operator.new[](local_410 + 1);
        ppuVar11[2] = pcVar12;
        strcpy(pcVar12, local_418);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        if (local_3f8[0] != local_3e8)
        {
            operator.delete(local_3f8[0]);
        }
        if (local_418 != local_408)
        {
            operator.delete(local_418);
        }
        /* try { // try from 00104ecd to 00104f66 has its CatchHandler @ 0010604b */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Give a weapon : ", 0x10);
        std::basic_istream<char, std::char_traits<char>>::ignore();
        plVar13 = *(long **)(&__cxxabiv1::__class_type_info::vtable + *(long *)(std::cin + -0x18));
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            cVar5 = (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        else
        {
            cVar5 = *(char *)((long)plVar13 + 0x43);
        }
        std::getline<char, std::char_traits<char>, std::allocator<char>>((basic_istream *)&std::cin, (basic_string *)local_238, cVar5);
        local_3d8[0] = local_3c8;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_3d8, (char *)local_238[0], (int)local_238[0] + (int)local_238[1]);
        /* try { // try from 00104f76 to 00104f7a has its CatchHandler @ 0010602e */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 0xb));
        if (local_3d8[0] != local_3c8)
        {
            operator.delete(local_3d8[0]);
        }
        /* try { // try from 00104f96 to 00104f9a has its CatchHandler @ 0010604b */
        FUN_0010cac8(ppuVar11);
        if (local_238[0] != &local_228)
        {
            operator.delete(local_238[0]);
        }
        uVar15 = 1;
        break;
    case 7:
        local_238[0] = &local_228;
        local_238[1] = (undefined8 *)0x0;
        local_228 = (undefined *)((ulong)local_228._1_7_ << 8);
        local_3b8 = local_3a8;
        /* try { // try from 00105006 to 0010500a has its CatchHandler @ 001060d3 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_3b8, point_to_name, iVar6 + iVar7);
        local_398[0] = local_388;
        /* try { // try from 00105032 to 00105036 has its CatchHandler @ 00106099 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_398, message, (int)message + (int)local_5b0);
        /* try { // try from 00105040 to 00105044 has its CatchHandler @ 0010607c */
        ppuVar11 = (undefined **)operator.new(0x60);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 001050b5 to 001050b9 has its CatchHandler @ 001050e8 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_003109d8;
        /* try { // try from 001050e1 to 00105142 has its CatchHandler @ 00105160 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong) "Vampire");
        *(int *)(ppuVar11 + 1) = age;
        pcVar12 = (char *)operator.new[](local_3b0 + 1);
        ppuVar11[2] = pcVar12;
        strcpy(pcVar12, local_3b8);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        ppuVar11[0xb] = (undefined *)0x0;
        if (local_398[0] != local_388)
        {
            operator.delete(local_398[0]);
        }
        if (local_3b8 != local_3a8)
        {
            operator.delete(local_3b8);
        }
        /* try { // try from 001051a0 to 00105239 has its CatchHandler @ 001060d3 */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Add blood :", 0xb);
        std::basic_istream<char, std::char_traits<char>>::ignore();
        plVar13 = *(long **)(&__cxxabiv1::__class_type_info::vtable + *(long *)(std::cin + -0x18));
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            cVar5 = (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        else
        {
            cVar5 = *(char *)((long)plVar13 + 0x43);
        }
        std::getline<char, std::char_traits<char>, std::allocator<char>>((basic_istream *)&std::cin, (basic_string *)local_238, cVar5);
        local_378 = local_368;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_378, (char *)local_238[0],
                                 (int)local_238[0] + (int)local_238[1]);
        /* try { // try from 00105249 to 0010524d has its CatchHandler @ 001060b6 */
        __dest = (undefined *)operator.new[](local_370 + 1);
        puVar8 = local_378;
        ppuVar11[0xb] = __dest;
        memcpy(__dest, local_378, local_370);
        if (puVar8 != local_368)
        {
            operator.delete(puVar8);
        }
        /* try { // try from 00105285 to 00105289 has its CatchHandler @ 001060d3 */
        FUN_0010aae5(ppuVar11);
        if (local_238[0] != &local_228)
        {
            operator.delete(local_238[0]);
        }
        uVar15 = 1;
        break;
    case 8:
        local_238[0] = &local_228;
        local_238[1] = (undefined8 *)0x0;
        local_228 = (undefined *)((ulong)local_228._1_7_ << 8);
        local_358 = local_348;
        /* try { // try from 001052f5 to 001052f9 has its CatchHandler @ 0010615b */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_358, point_to_name, iVar6 + iVar7);
        local_338[0] = local_328;
        /* try { // try from 00105321 to 00105325 has its CatchHandler @ 00106121 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_338, message, (int)message + (int)local_5b0);
        /* try { // try from 0010532f to 00105333 has its CatchHandler @ 00106104 */
        ppuVar11 = (undefined **)operator.new(0x78);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 001053a4 to 001053a8 has its CatchHandler @ 001053eb */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_00310af0;
        ppuVar11[0xb] = (undefined *)(ppuVar11 + 0xd);
        ppuVar11[0xc] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 0xd) = 0;
        /* try { // try from 001053e4 to 00105445 has its CatchHandler @ 00105448 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong) "Yuki-onna");
        *(int *)(ppuVar11 + 1) = age;
        pcVar12 = (char *)operator.new[](local_350 + 1);
        ppuVar11[2] = pcVar12;
        strcpy(pcVar12, local_358);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        if (local_338[0] != local_328)
        {
            operator.delete(local_338[0]);
        }
        if (local_358 != local_348)
        {
            operator.delete(local_358);
        }
        /* try { // try from 001054a9 to 00105542 has its CatchHandler @ 0010615b */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Cold :", 6);
        std::basic_istream<char, std::char_traits<char>>::ignore();
        plVar13 = *(long **)(&__cxxabiv1::__class_type_info::vtable + *(long *)(std::cin + -0x18));
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            cVar5 = (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        else
        {
            cVar5 = *(char *)((long)plVar13 + 0x43);
        }
        std::getline<char, std::char_traits<char>, std::allocator<char>>((basic_istream *)&std::cin, (basic_string *)local_238, cVar5);
        local_318[0] = local_308;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_318, (char *)local_238[0], (int)local_238[0] + (int)local_238[1]);
        /* try { // try from 00105552 to 00105632 has its CatchHandler @ 0010613e */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 0xb));
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "So cold........", 0xf);
        plVar13 = *(long **)(&std::__cxx11::
                                 basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                             *(long *)(std::cout + -0x18));
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        std::basic_ostream<char, std::char_traits<char>>::put(-8);
        std::basic_ostream<char, std::char_traits<char>>::flush();
        plVar9 = (long *)std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, ppuVar11[0xb], (long)ppuVar11[0xc]);
        plVar13 = *(long **)((long)plVar9 + *(long *)(*plVar9 + -0x18) + 0xf0);
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        std::basic_ostream<char, std::char_traits<char>>::put((char)plVar9);
        std::basic_ostream<char, std::char_traits<char>>::flush();
        if (local_318[0] != local_308)
        {
            operator.delete(local_318[0]);
        }
        /* try { // try from 0010564e to 00105652 has its CatchHandler @ 0010615b */
        FUN_0010d141(ppuVar11);
        if (local_238[0] != &local_228)
        {
            operator.delete(local_238[0]);
        }
        uVar15 = 1;
        break;
    case 9:
        local_238[0] = &local_228;
        local_238[1] = (undefined8 *)0x0;
        local_228 = (undefined *)((ulong)local_228._1_7_ << 8);
        local_2f8 = local_2e8;
        /* try { // try from 001056be to 001056c2 has its CatchHandler @ 001061e3 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_2f8, point_to_name, iVar6 + iVar7);
        local_2d8[0] = local_2c8;
        /* try { // try from 001056ea to 001056ee has its CatchHandler @ 001061a9 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_2d8, message, (int)message + (int)local_5b0);
        /* try { // try from 001056f8 to 001056fc has its CatchHandler @ 0010618c */
        ppuVar11 = (undefined **)operator.new(0x80);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 0010576d to 00105771 has its CatchHandler @ 001057b4 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_00310b28;
        ppuVar11[0xc] = (undefined *)(ppuVar11 + 0xe);
        ppuVar11[0xd] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 0xe) = 0;
        /* try { // try from 001057ad to 0010580e has its CatchHandler @ 00105811 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong) "Kasa-obake");
        *(int *)(ppuVar11 + 1) = age;
        pcVar12 = (char *)operator.new[](local_2f0 + 1);
        ppuVar11[2] = pcVar12;
        strcpy(pcVar12, local_2f8);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        if (local_2d8[0] != local_2c8)
        {
            operator.delete(local_2d8[0]);
        }
        if (local_2f8 != local_2e8)
        {
            operator.delete(local_2f8);
        }
        /* try { // try from 00105872 to 00105936 has its CatchHandler @ 001061e3 */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "foot number :", 0xd);
        std::basic_istream<char, std::char_traits<char>>::operator>>((basic_istream<char, std::char_traits<char>> *)&std::cin, &local_5dc);
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Eyes : ", 7);
        std::basic_istream<char, std::char_traits<char>>::ignore();
        plVar13 = *(long **)(&__cxxabiv1::__class_type_info::vtable + *(long *)(std::cin + -0x18));
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            cVar5 = (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        else
        {
            cVar5 = *(char *)((long)plVar13 + 0x43);
        }
        std::getline<char, std::char_traits<char>, std::allocator<char>>((basic_istream *)&std::cin, (basic_string *)local_238, cVar5);
        local_2b8[0] = local_2a8;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_2b8, (char *)local_238[0], (int)local_238[0] + (int)local_238[1]);
        *(int *)(ppuVar11 + 0xb) = local_5dc;
        /* try { // try from 0010594f to 00105a2a has its CatchHandler @ 001061c6 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 0xc));
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Input to echo :", 0xf);
        uVar10 = read(0, local_a8, 0x14);
        local_a8[uVar10 & 0xffffffff] = '\0';
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "echo :", 6);
        uVar10 = 0xffffffffffffffff;
        pcVar12 = local_a8;
        do
        {
            if (uVar10 == 0)
                break;
            uVar10 = uVar10 - 1;
            cVar5 = *pcVar12;
            pcVar12 = pcVar12 + (ulong)bVar17 * -2 + 1;
        } while (cVar5 != '\0');
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, local_a8, ~uVar10 - 1);
        plVar13 = *(long **)(&std::__cxx11::
                                 basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                             *(long *)(std::cout + -0x18));
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        std::basic_ostream<char, std::char_traits<char>>::put(-8);
        std::basic_ostream<char, std::char_traits<char>>::flush();
        if (local_2b8[0] != local_2a8)
        {
            operator.delete(local_2b8[0]);
        }
        /* try { // try from 00105a46 to 00105a4a has its CatchHandler @ 001061e3 */
        FUN_0010d7ba(ppuVar11);
        if (local_238[0] != &local_228)
        {
            operator.delete(local_238[0]);
        }
        uVar15 = 1;
        break;
    case 10:
        local_238[0] = &local_228;
        local_238[1] = (undefined8 *)0x0;
        local_228 = (undefined *)((ulong)local_228._1_7_ << 8);
        local_298 = local_288;
        /* try { // try from 00105ab6 to 00105aba has its CatchHandler @ 00106247 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_298, point_to_name, iVar6 + iVar7);
        local_278[0] = local_268;
        /* try { // try from 00105ae2 to 00105ae6 has its CatchHandler @ 0010622a */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)local_278, message, (int)message + (int)local_5b0);
        /* try { // try from 00105af0 to 00105af4 has its CatchHandler @ 0010620d */
        ppuVar11 = (undefined **)operator.new(0x60);
        *ppuVar11 = (undefined *)&PTR_FUN_003109a0;
        *(undefined4 *)(ppuVar11 + 1) = 0;
        ppuVar11[2] = (undefined *)0x0;
        ppuVar11[3] = (undefined *)(ppuVar11 + 5);
        ppuVar11[4] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 5) = 0;
        ppuVar11[7] = (undefined *)(ppuVar11 + 9);
        ppuVar11[8] = (undefined *)0x0;
        *(undefined *)(ppuVar11 + 9) = 0;
        /* try { // try from 00105b65 to 00105b69 has its CatchHandler @ 00105b98 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, (char *)0x0, (ulong) "Ghost");
        *ppuVar11 = (undefined *)&PTR_FUN_00310ab8;
        /* try { // try from 00105b91 to 00105bf2 has its CatchHandler @ 00105bf5 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_replace((ulong)(ppuVar11 + 3), 0, ppuVar11[4], (ulong)&DAT_0010e299);
        *(int *)(ppuVar11 + 1) = age;
        pcVar12 = (char *)operator.new[](local_290 + 1);
        ppuVar11[2] = pcVar12;
        strcpy(pcVar12, local_298);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)(ppuVar11 + 7));
        if (local_278[0] != local_268)
        {
            operator.delete(local_278[0]);
        }
        if (local_298 != local_288)
        {
            operator.delete(local_298);
        }
        /* try { // try from 00105c48 to 00105d09 has its CatchHandler @ 00106247 */
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Your lightsaber : ", 0x12);
        std::basic_istream<char, std::char_traits<char>>::ignore();
        plVar13 = *(long **)(&__cxxabiv1::__class_type_info::vtable + *(long *)(std::cin + -0x18));
        if (plVar13 == (long *)0x0)
        {
            plVar13 = (long *)std::__throw_bad_cast();
        }
        if (*(char *)(plVar13 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            cVar5 = (**(code **)(*plVar13 + 0x30))(plVar13, 10);
        }
        else
        {
            cVar5 = *(char *)((long)plVar13 + 0x43);
        }
        std::getline<char, std::char_traits<char>, std::allocator<char>>((basic_istream *)&std::cin, (basic_string *)local_238, cVar5);
        local_258 = local_248;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            _M_construct<char *>((char *)&local_258, (char *)local_238[0],
                                 (int)local_238[0] + (int)local_238[1]);
        ppuVar11[0xb] = local_258;
        if (local_258 != local_248)
        {
            operator.delete(local_258);
        }
        FUN_0010b76d(ppuVar11);
        if (local_238[0] != &local_228)
        {
            operator.delete(local_238[0]);
        }
        uVar15 = 1;
    }
    if (message != local_5a8)
    {
        operator.delete(message);
    }
    if (point_to_name != local_5c8)
    {
        operator.delete(point_to_name);
    }
    if (local_40 != *(long *)(in_FS_OFFSET + 0x28))
    {
        /* WARNING: Subroutine does not return */
        __stack_chk_fail();
    }
    return uVar15;
}

undefined8 FUN_0010311f(void)

{
    void *__src;
    void *__dest;
    long lVar1;
    long *plVar2;
    undefined8 uVar3;
    long in_FS_OFFSET;
    uint local_14;

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    if ((long)DAT_00311038 - DAT_00311030 >> 3 == 0) {
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[31mNo ghost in the party\x1b[0m ", 0x1f);
        plVar2 = *(long **)(&std::__cxx11::
                                basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                            *(long *)(std::cout + -0x18));
        if (plVar2 == (long *)0x0) {
            std::__throw_bad_cast();
        }
        if (*(char *)(plVar2 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            (**(code **)(*plVar2 + 0x30))(plVar2, 10);
        }
        std::basic_ostream<char, std::char_traits<char>>::put(-8);
        std::basic_ostream<char, std::char_traits<char>>::flush();
        uVar3 = 0;
    }
    else
    {
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout,
                                                            "Choose a ghost which you want to remove from the party : ", 0x39);
        std::basic_istream<char, std::char_traits<char>>::_M_extract<unsigned_int>((uint *)&std::cin);
        if ((ulong)local_14 < (ulong)((long)DAT_00311038 - DAT_00311030 >> 3))
        {
            plVar2 = *(long **)(DAT_00311030 + (ulong)local_14 * 8);
            if (plVar2 != (long *)0x0)
            {
                (**(code **)(*plVar2 + 0x20))();
            }
            __dest = (void *)(DAT_00311030 + (ulong)local_14 * 8);
            __src = (void *)((long)__dest + 8);
            if ((DAT_00311038 != __src) && ((long)DAT_00311038 - (long)__src >> 3 != 0))
            {
                memmove(__dest, __src, (long)DAT_00311038 - (long)__src);
            }
            DAT_00311038 = (void *)((long)DAT_00311038 + -8);
            uVar3 = 1;
        }
        else
        {
            std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[31mInvaild index\x1b[0m", 0x16);
            plVar2 = *(long **)(&std::__cxx11::
                                    basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                                *(long *)(std::cout + -0x18));
            if (plVar2 == (long *)0x0) {
                std::__throw_bad_cast();
            }
            if (*(char *)(plVar2 + 7) == '\0') {
                std::ctype<char>::_M_widen_init();
                (**(code **)(*plVar2 + 0x30))(plVar2, 10);
            }
            std::basic_ostream<char, std::char_traits<char>>::put(-8);
            std::basic_ostream<char, std::char_traits<char>>::flush();
            uVar3 = 0;
        }
    }
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28))
    {
        return uVar3;
    }
    __stack_chk_fail();
}


undefined8 FUN_0010b76d(long *param_1) {
    char cVar1;
    long *plVar2;
    undefined8 uVar3;
    size_t __n;
    ulong uVar4;
    char *pcVar5;
    long in_FS_OFFSET;
    byte bVar6;
    int local_94;
    long *local_90;
    undefined **local_88;
    undefined4 local_80;
    char *local_78;
    undefined *local_70;
    undefined8 local_68;
    undefined local_60[16];
    undefined *local_50;
    undefined8 local_48;
    undefined local_40[16];
    long local_30;
    long local_20;

    bVar6 = 0;
    local_20 = *(long *)(in_FS_OFFSET + 0x28);
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "1.Join       ", 0xd);
    plVar2 = *(long **)(&std::__cxx11::
                            basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                        *(long *)(std::cout + -0x18));
    if (plVar2 == (long *)0x0)
    {
        std::__throw_bad_cast();
    }
    if (*(char *)(plVar2 + 7) == '\0')
    {
        std::ctype<char>::_M_widen_init();
        (**(code **)(*plVar2 + 0x30))(plVar2, 10);
    }
    std::basic_ostream<char, std::char_traits<char>>::put(-8);
    std::basic_ostream<char, std::char_traits<char>>::flush();
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "2.Give up", 9);
    plVar2 = *(long **)(&std::__cxx11::
                            basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                        *(long *)(std::cout + -0x18));
    if (plVar2 == (long *)0x0)
    {
        std::__throw_bad_cast();
    }
    if (*(char *)(plVar2 + 7) == '\0')
    {
        std::ctype<char>::_M_widen_init();
        (**(code **)(*plVar2 + 0x30))(plVar2, 10);
    }
    std::basic_ostream<char, std::char_traits<char>>::put(-8);
    std::basic_ostream<char, std::char_traits<char>>::flush();
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "3.Join and hear what the ghost say", 0x22);
    plVar2 = *(long **)(&std::__cxx11::
                            basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                        *(long *)(std::cout + -0x18));
    if (plVar2 == (long *)0x0)
    {
        std::__throw_bad_cast();
    }
    if (*(char *)(plVar2 + 7) == '\0')
    {
        std::ctype<char>::_M_widen_init();
        (**(code **)(*plVar2 + 0x30))(plVar2, 10);
    }
    std::basic_ostream<char, std::char_traits<char>>::put(-8);
    std::basic_ostream<char, std::char_traits<char>>::flush();
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Your choice : ", 0xe);
    std::basic_istream<char, std::char_traits<char>>::_M_extract<unsigned_int>((uint *)&std::cin);
    if (_close != 0)
    {
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Format error !", 0xe);
        std::endl<char, std::char_traits<char>>((basic_ostream *)&std::cout);
        exit(0);
    }
    if (local_94 == 2)
    {
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[31mThe ghost is not joining the party\x1b[0m", 0x2b);
        plVar2 = *(long **)(&std::__cxx11::
                                basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                            *(long *)(std::cout + -0x18));
        if (plVar2 == (long *)0x0)
        {
            std::__throw_bad_cast();
        }
        if (*(char *)(plVar2 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            (**(code **)(*plVar2 + 0x30))(plVar2, 10);
        }
        std::basic_ostream<char, std::char_traits<char>>::put(-8);
        std::basic_ostream<char, std::char_traits<char>>::flush();
        uVar3 = 0;
        if (param_1 != (long *)0x0)
        {
            (**(code **)(*param_1 + 0x20))(param_1);
            uVar3 = 0;
        }
    }
    else
    {
        if (local_94 == 3)
        {
            if (DAT_00311038 == DAT_00311040)
            {
                local_90 = param_1;
                FUN_00109c3c(&DAT_00311030, DAT_00311038, &local_90);
            }
            else
            {
                if (DAT_00311038 != (long **)0x0)
                {
                    *DAT_00311038 = param_1;
                }
                DAT_00311038 = DAT_00311038 + 1;
                local_90 = param_1;
            }
            local_88 = &PTR_FUN_003109a0;
            local_70 = local_60;
            local_68 = 0;
            local_60[0] = 0;
            local_50 = local_40;
            local_48 = 0;
            local_40[0] = 0;
            uVar4 = 0xffffffffffffffff;
            pcVar5 = (char *)param_1[2];
            do
            {
                if (uVar4 == 0)
                    break;
                uVar4 = uVar4 - 1;
                cVar1 = *pcVar5;
                pcVar5 = pcVar5 + (ulong)bVar6 * -2 + 1;
            } while (cVar1 != '\0');
            /* try { // try from 0010bb1d to 0010bb55 has its CatchHandler @ 0010bb58 */
            local_78 = (char *)operator.new[](~uVar4);
            strcpy(local_78, (char *)param_1[2]);
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)&local_70);
            local_80 = *(undefined4 *)(param_1 + 1);
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)&local_50);
            local_88 = &PTR_FUN_00310ab8;
            local_30 = param_1[0xb];
            /* try { // try from 0010bba9 to 0010bbad has its CatchHandler @ 0010bd4a */
            FUN_00109b39(&local_88);
            local_88 = &PTR_FUN_003109a0;
            local_80 = 0;
            local_48 = 0;
            *local_50 = 0;
            local_68 = 0;
            *local_70 = 0;
            __n = malloc_usable_size(local_78);
            memset(local_78, 0, __n);
            if (local_78 != (char *)0x0)
            {
                operator.delete[](local_78);
            }
            if (local_50 != local_40)
            {
                operator.delete(local_50);
            }
            if (local_70 != local_60)
            {
                operator.delete(local_70);
            }
            std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[32mThe ghost is joining the party\x1b[0m", 0x27);
            plVar2 = *(long **)(&std::__cxx11::
                                    basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                                *(long *)(std::cout + -0x18));
            if (plVar2 == (long *)0x0)
            {
                std::__throw_bad_cast();
            }
            if (*(char *)(plVar2 + 7) == '\0')
            {
                std::ctype<char>::_M_widen_init();
                (**(code **)(*plVar2 + 0x30))(plVar2, 10);
            }
            std::basic_ostream<char, std::char_traits<char>>::put(-8);
            std::basic_ostream<char, std::char_traits<char>>::flush();
            uVar3 = 1;
        }
        else
        {
            if (local_94 == 1)
            {
                if (DAT_00311038 == DAT_00311040)
                {
                    local_90 = param_1;
                    FUN_00109c3c(&DAT_00311030, DAT_00311038, &local_90);
                }
                else
                {
                    if (DAT_00311038 != (long **)0x0)
                    {
                        *DAT_00311038 = param_1;
                    }
                    DAT_00311038 = DAT_00311038 + 1;
                    local_90 = param_1;
                }
                std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[32mThe ghost is joining the party\x1b[0m", 0x27);
                plVar2 = *(long **)(&std::__cxx11::
                                        basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::
                                            VTT +
                                    *(long *)(std::cout + -0x18));
                if (plVar2 == (long *)0x0)
                {
                    std::__throw_bad_cast();
                }
                if (*(char *)(plVar2 + 7) == '\0')
                {
                    std::ctype<char>::_M_widen_init();
                    (**(code **)(*plVar2 + 0x30))(plVar2, 10);
                }
                std::basic_ostream<char, std::char_traits<char>>::put(-8);
                std::basic_ostream<char, std::char_traits<char>>::flush();
                uVar3 = 1;
            }
            else
            {
                std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[31mInvaild choice\x1b[0m", 0x17);
                plVar2 = *(long **)(&std::__cxx11::
                                        basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::
                                            VTT +
                                    *(long *)(std::cout + -0x18));
                if (plVar2 == (long *)0x0)
                {
                    std::__throw_bad_cast();
                }
                if (*(char *)(plVar2 + 7) == '\0')
                {
                    std::ctype<char>::_M_widen_init();
                    (**(code **)(*plVar2 + 0x30))(plVar2, 10);
                }
                std::basic_ostream<char, std::char_traits<char>>::put(-8);
                std::basic_ostream<char, std::char_traits<char>>::flush();
                uVar3 = 0;
                if (param_1 != (long *)0x0)
                {
                    (**(code **)(*param_1 + 0x20))(param_1);
                    uVar3 = 0;
                }
            }
        }
    }
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28))
    {
        return uVar3;
    }
    __stack_chk_fail();
}


undefined8 FUN_0010aae5(long *param_1) {
    char cVar1;
    long *plVar2;
    undefined8 uVar3;
    size_t __n;
    ulong uVar4;
    char *pcVar5;
    long in_FS_OFFSET;
    byte bVar6;
    int local_94;
    long *local_90;
    undefined **local_88;
    undefined4 local_80;
    char *local_78;
    undefined *local_70;
    undefined8 local_68;
    undefined local_60[16];
    undefined *local_50;
    undefined8 local_48;
    undefined local_40[16];
    void *local_30;
    long local_20;

    bVar6 = 0;
    local_20 = *(long *)(in_FS_OFFSET + 0x28);
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "1.Join       ", 0xd);
    plVar2 = *(long **)(&std::__cxx11::
                            basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                        *(long *)(std::cout + -0x18));
    if (plVar2 == (long *)0x0)
    {
        std::__throw_bad_cast();
    }
    if (*(char *)(plVar2 + 7) == '\0')
    {
        std::ctype<char>::_M_widen_init();
        (**(code **)(*plVar2 + 0x30))(plVar2, 10);
    }
    std::basic_ostream<char, std::char_traits<char>>::put(-8);
    std::basic_ostream<char, std::char_traits<char>>::flush();
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "2.Give up", 9);
    plVar2 = *(long **)(&std::__cxx11::
                            basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                        *(long *)(std::cout + -0x18));
    if (plVar2 == (long *)0x0)
    {
        std::__throw_bad_cast();
    }
    if (*(char *)(plVar2 + 7) == '\0')
    {
        std::ctype<char>::_M_widen_init();
        (**(code **)(*plVar2 + 0x30))(plVar2, 10);
    }
    std::basic_ostream<char, std::char_traits<char>>::put(-8);
    std::basic_ostream<char, std::char_traits<char>>::flush();
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "3.Join and hear what the ghost say", 0x22);
    plVar2 = *(long **)(&std::__cxx11::
                            basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                        *(long *)(std::cout + -0x18));
    if (plVar2 == (long *)0x0)
    {
        std::__throw_bad_cast();
    }
    if (*(char *)(plVar2 + 7) == '\0')
    {
        std::ctype<char>::_M_widen_init();
        (**(code **)(*plVar2 + 0x30))(plVar2, 10);
    }
    std::basic_ostream<char, std::char_traits<char>>::put(-8);
    std::basic_ostream<char, std::char_traits<char>>::flush();
    std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Your choice : ", 0xe);
    std::basic_istream<char, std::char_traits<char>>::_M_extract<unsigned_int>((uint *)&std::cin);
    if (_close != 0)
    {
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "Format error !", 0xe);
        std::endl<char, std::char_traits<char>>((basic_ostream *)&std::cout);
        /* WARNING: Subroutine does not return */
        exit(0);
    }
    if (local_94 == 2)
    {
        std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[31mThe ghost is not joining the party\x1b[0m", 0x2b);
        plVar2 = *(long **)(&std::__cxx11::
                                basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                            *(long *)(std::cout + -0x18));
        if (plVar2 == (long *)0x0)
        {
            std::__throw_bad_cast();
        }
        if (*(char *)(plVar2 + 7) == '\0')
        {
            std::ctype<char>::_M_widen_init();
            (**(code **)(*plVar2 + 0x30))(plVar2, 10);
        }
        std::basic_ostream<char, std::char_traits<char>>::put(-8);
        std::basic_ostream<char, std::char_traits<char>>::flush();
        uVar3 = 0;
        if (param_1 != (long *)0x0)
        {
            (**(code **)(*param_1 + 0x20))(param_1);
            uVar3 = 0;
        }
    }
    else
    {
        if (local_94 == 3)
        {
            if (DAT_00311038 == DAT_00311040)
            {
                local_90 = param_1;
                FUN_00109c3c(&DAT_00311030, DAT_00311038, &local_90);
            }
            else
            {
                if (DAT_00311038 != (long **)0x0)
                {
                    *DAT_00311038 = param_1;
                }
                DAT_00311038 = DAT_00311038 + 1;
                local_90 = param_1;
            }
            local_88 = &PTR_FUN_003109a0;
            local_70 = local_60;
            local_68 = 0;
            local_60[0] = 0;
            local_50 = local_40;
            local_48 = 0;
            local_40[0] = 0;
            uVar4 = 0xffffffffffffffff;
            pcVar5 = (char *)param_1[2];
            do
            {
                if (uVar4 == 0)
                    break;
                uVar4 = uVar4 - 1;
                cVar1 = *pcVar5;
                pcVar5 = pcVar5 + (ulong)bVar6 * -2 + 1;
            } while (cVar1 != '\0');
            /* try { // try from 0010ae95 to 0010aecd has its CatchHandler @ 0010aed0 */
            local_78 = (char *)operator.new[](~uVar4);
            strcpy(local_78, (char *)param_1[2]);
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)&local_70);
            local_80 = *(undefined4 *)(param_1 + 1);
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_assign((basic_string *)&local_50);
            local_88 = &PTR_FUN_003109d8;
            local_30 = (void *)param_1[0xb];
            /* try { // try from 0010af21 to 0010af25 has its CatchHandler @ 0010b0e1 */
            FUN_00109830(&local_88);
            local_88 = &PTR_FUN_003109d8;
            if (local_30 != (void *)0x0)
            {
                operator.delete[](local_30);
            }
            local_88 = &PTR_FUN_003109a0;
            local_80 = 0;
            local_48 = 0;
            *local_50 = 0;
            local_68 = 0;
            *local_70 = 0;
            __n = malloc_usable_size(local_78);
            memset(local_78, 0, __n);
            if (local_78 != (char *)0x0)
            {
                operator.delete[](local_78);
            }
            if (local_50 != local_40)
            {
                operator.delete(local_50);
            }
            if (local_70 != local_60)
            {
                operator.delete(local_70);
            }
            std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[32mThe ghost is joining the party\x1b[0m", 0x27);
            plVar2 = *(long **)(&std::__cxx11::
                                    basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::VTT +
                                *(long *)(std::cout + -0x18));
            if (plVar2 == (long *)0x0)
            {
                std::__throw_bad_cast();
            }
            if (*(char *)(plVar2 + 7) == '\0')
            {
                std::ctype<char>::_M_widen_init();
                (**(code **)(*plVar2 + 0x30))(plVar2, 10);
            }
            std::basic_ostream<char, std::char_traits<char>>::put(-8);
            std::basic_ostream<char, std::char_traits<char>>::flush();
            uVar3 = 1;
        }
        else
        {
            if (local_94 == 1)
            {
                if (DAT_00311038 == DAT_00311040)
                {
                    local_90 = param_1;
                    FUN_00109c3c(&DAT_00311030, DAT_00311038, &local_90);
                }
                else
                {
                    if (DAT_00311038 != (long **)0x0)
                    {
                        *DAT_00311038 = param_1;
                    }
                    DAT_00311038 = DAT_00311038 + 1;
                    local_90 = param_1;
                }
                std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[32mThe ghost is joining the party\x1b[0m", 0x27);
                plVar2 = *(long **)(&std::__cxx11::
                                        basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::
                                            VTT +
                                    *(long *)(std::cout + -0x18));
                if (plVar2 == (long *)0x0)
                {
                    std::__throw_bad_cast();
                }
                if (*(char *)(plVar2 + 7) == '\0')
                {
                    std::ctype<char>::_M_widen_init();
                    (**(code **)(*plVar2 + 0x30))(plVar2, 10);
                }
                std::basic_ostream<char, std::char_traits<char>>::put(-8);
                std::basic_ostream<char, std::char_traits<char>>::flush();
                uVar3 = 1;
            }
            else
            {
                std::__ostream_insert<char, std::char_traits<char>>((basic_ostream *)&std::cout, "\x1b[31mInvaild choice\x1b[0m", 0x17);
                plVar2 = *(long **)(&std::__cxx11::
                                        basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::
                                            VTT +
                                    *(long *)(std::cout + -0x18));
                if (plVar2 == (long *)0x0)
                {
                    std::__throw_bad_cast();
                }
                if (*(char *)(plVar2 + 7) == '\0')
                {
                    std::ctype<char>::_M_widen_init();
                    (**(code **)(*plVar2 + 0x30))(plVar2, 10);
                }
                std::basic_ostream<char, std::char_traits<char>>::put(-8);
                std::basic_ostream<char, std::char_traits<char>>::flush();
                uVar3 = 0;
                if (param_1 != (long *)0x0)
                {
                    (**(code **)(*param_1 + 0x20))(param_1);
                    uVar3 = 0;
                }
            }
        }
    }
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28))
    {
        return uVar3;
    }
    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
}