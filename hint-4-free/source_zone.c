
long *BLTRotateRight(long *param_1, long *param_2) {
    long local_80;
    long local_78;
    long local_70;
    long local_68;
    long local_58;
    long local_50;
    long local_48;
    long local_40;
    long local_38;
    long local_28;
    long *local_10;

    local_10 = param_1;
    if (param_2 != (long *)0x0) {
        param_1[1] = param_2[2];
        param_2[2] = (long)param_1;
        if (param_1[1] == 0) {
            local_28 = 0;
        }
        else
        {
            local_28 = *(long *)param_1[1];
        }
        if (param_1[2] == 0)
        {
            local_38 = 0;
        }
        else
        {
            local_38 = *(long *)param_1[2];
        }
        if (local_38 < local_28)
        {
            if (param_1[1] == 0)
            {
                local_40 = 0;
            }
            else
            {
                local_40 = *(long *)param_1[1];
            }
            local_48 = local_40;
        }
        else
        {
            if (param_1[2] == 0)
            {
                local_50 = 0;
            }
            else
            {
                local_50 = *(long *)param_1[2];
            }
            local_48 = local_50;
        }
        *param_1 = local_48 + 1;
        if (param_2[1] == 0)
        {
            local_58 = 0;
        }
        else
        {
            local_58 = *(long *)param_2[1];
        }
        if (param_2[2] == 0)
        {
            local_68 = 0;
        }
        else
        {
            local_68 = *(long *)param_2[2];
        }
        if (local_68 < local_58)
        {
            if (param_2[1] == 0)
            {
                local_70 = 0;
            }
            else
            {
                local_70 = *(long *)param_2[1];
            }
            local_78 = local_70;
        }
        else
        {
            if (param_2[2] == 0)
            {
                local_80 = 0;
            }
            else
            {
                local_80 = *(long *)param_2[2];
            }
            local_78 = local_80;
        }
        *param_2 = local_78 + 1;
        local_10 = param_2;
    }
    return local_10;
}

long *BLTInsert(long *param_1, long *param_2, code *param_3)

{
    int iVar1;
    long lVar2;
    long local_80;
    long local_70;
    long local_68;
    long local_60;
    long local_58;
    long local_50;
    long local_40;
    long *local_18;
    long *local_10;

    local_10 = param_2;
    if ((param_1 != (long *)0x0) && (param_2 != (long *)0x0))
    {
        iVar1 = (*param_3)(param_2, param_1);
        if (iVar1 < 0)
        {
            lVar2 = BLTInsert(param_1[1], param_2, param_3);
            param_1[1] = lVar2;
        }
        else
        {
            if (iVar1 < 1)
            {
                return param_1;
            }
            lVar2 = BLTInsert(param_1[2], param_2, param_3);
            param_1[2] = lVar2;
        }
        if (param_1[1] == 0)
        {
            local_40 = 0;
        }
        else
        {
            local_40 = *(long *)param_1[1];
        }
        if (param_1[2] == 0)
        {
            local_50 = 0;
        }
        else
        {
            local_50 = *(long *)param_1[2];
        }
        if (local_50 < local_40)
        {
            if (param_1[1] == 0)
            {
                local_58 = 0;
            }
            else
            {
                local_58 = *(long *)param_1[1];
            }
            local_60 = local_58;
        }
        else
        {
            if (param_1[2] == 0)
            {
                local_68 = 0;
            }
            else
            {
                local_68 = *(long *)param_1[2];
            }
            local_60 = local_68;
        }
        *param_1 = local_60 + 1;
        if (param_1[1] == 0)
        {
            local_70 = 0;
        }
        else
        {
            local_70 = *(long *)param_1[1];
        }
        if (param_1[2] == 0)
        {
            local_80 = 0;
        }
        else
        {
            local_80 = *(long *)param_1[2];
        }
        local_70 = local_70 - local_80;
        iVar1 = (*param_3)(param_2, param_1[1]);
        local_18 = param_1;
        if ((1 < local_70) && (iVar1 < 0))
        {
            local_18 = (long *)BLTRotateRight(param_1, param_1[1]);
        }
        if ((1 < local_70) && (-1 < iVar1))
        {
            lVar2 = BLTRotateLeft(local_18[1], *(undefined8 *)(local_18[1] + 0x10));
            local_18[1] = lVar2;
            local_18 = (long *)BLTRotateRight(local_18, local_18[1]);
        }
        iVar1 = (*param_3)(param_2, local_18[2]);
        if ((local_70 < -1) && (0 < iVar1))
        {
            local_18 = (long *)BLTRotateLeft(local_18, local_18[2]);
        }
        if ((local_70 < -1) && (iVar1 < 1))
        {
            lVar2 = BLTRotateRight(local_18[2], *(undefined8 *)(local_18[2] + 8));
            local_18[2] = lVar2;
            local_18 = (long *)BLTRotateLeft(local_18, local_18[2]);
        }
        local_10 = local_18;
    }
    return local_10;
}

void zone_create(char *param_1, undefined8 param_2)
{
    int iVar1;

    iVar1 = strncmp(param_1, "zone_bootstrap", 0xf);
    if (iVar1 == 0)
    {
        fprintf(stderr, "Invalid zone name\n");
        abort();
    }
    zone_create_internal(param_1, param_2, 0);
    return;
}

void zone_create_internal(char *param_1, long param_2, undefined param_3)
{
    ulong uVar1;
    ulong uVar2;
    char *__dest;
    long lVar3;

    if (0xf < zone_table[1])
    {
        fprintf(stderr, "Unable to make a new zone for your zone %s\n", param_1);
        /* WARNING: Subroutine does not return */
        abort();
    }
    uVar2 = hash_string(param_1);
    uVar2 = uVar2 % *zone_table;
    uVar1 = zone_table[(uVar2 & 0xffffffff) + 0x16];
    __dest = (char *)zone_alloc_internal("zone_bootstrap");
    if (__dest == (char *)0x0)
    {
        fprintf(stderr, "Unable to create zone %s\n", param_1);
        abort();
    }
    memset(__dest, 0, 0xa0);
    strncpy(__dest, param_1, 0x3f);
    *(uint *)(__dest + 0x40) = *(uint *)(__dest + 0x40) | 1;
    if (uVar1 == 0)
    {
        zone_table[(uVar2 & 0xffffffff) + 0x16] = (ulong)__dest;
        zone_table[1] = zone_table[1] + 1;
    }
    else
    {
        lVar3 = BLTInsert(uVar1 + 0x88, __dest + 0x88, zone_name_cmp);
        zone_table[(uVar2 & 0xffffffff) + 0x16] = lVar3 - 0x88;
    }
    zone_init(__dest, 0, param_2 + 0x10, param_3);
    return;
}

ulong zone_alloc_internal(undefined8 param_1)

{
    long lVar1;
    long lVar2;
    ulong uVar3;
    char *pcVar4;
    ulong uVar5;
    char cVar6;
    char cVar7;
    char cVar8;
    char cVar9;
    char cVar10;
    char cVar11;
    char cVar12;
    char cVar13;
    char cVar14;
    char cVar15;
    char cVar16;
    char cVar17;
    char cVar18;
    char cVar19;
    char cVar20;
    byte bVar21;
    ulong local_40;
    ulong *local_30;

    lVar2 = zone_table_get_zone(param_1);
    if (lVar2 == 0)
    {
        fprintf(stderr, "Invalid zone %s\n", param_1);
        /* WARNING: Subroutine does not return */
        abort();
    }
    if (*(long *)(lVar2 + 0x60) != 0)
    {
        if (*(long *)(lVar2 + 0x60) == 0)
        {
            /* WARNING: Subroutine does not return */
            __assert_fail("zone->num_freed != 0", "/home/notes/src/libzone/libzone.c", 0x208,
                          "void *zone_alloc_internal(const char *)");
        }
        if ((*(long *)(lVar2 + 0x78) == 0) || (*(long *)(*(long *)(lVar2 + 0x78) + 0x10) != 0))
        {
            local_30 = *(ulong **)(lVar2 + 0x70);
            *(undefined8 *)(lVar2 + 0x78) = 0;
            local_40 = 0xffffffff;
            do
            {
                if (*(long *)((long)local_30 + 0x10) == 0)
                {
                    local_30 = *(ulong **)((long)local_30 + 0x28);
                }
                else
                {
                    if (*(ulong *)((long)local_30 + 0x10) < local_40)
                    {
                        *(ulong **)(lVar2 + 0x78) = local_30;
                        local_40 = *(ulong *)((long)local_30 + 0x10);
                    }
                    local_30 = *(ulong **)((long)local_30 + 0x28);
                }
            } while (local_30 != (ulong *)*(long *)(lVar2 + 0x70));
            if (*(long *)(lVar2 + 0x78) == 0)
            {
                /* WARNING: Subroutine does not return */
                __assert_fail("zone->page_min_num_free != NULL", "/home/notes/src/libzone/libzone.c", 0x21e,
                              "void *zone_alloc_internal(const char *)");
            }
        }
        lVar1 = *(long *)(lVar2 + 0x78);
        uVar3 = bitmap_find_idx();
        if ((long)uVar3 < 0)
        {
            fprintf(stderr, "Unable to find any free chunk in zone %s\n", lVar2);
            /* WARNING: Subroutine does not return */
            abort();
        }
        bVar21 = (byte)uVar3 & 0x3f;
        if ((*(ulong *)(lVar1 + 0x38 + (uVar3 >> 6 & 0xffffffff) * 8) >> bVar21 & 1) != 0)
        {
            uVar5 = uVar3 >> 6 & 0xffffffff;
            *(ulong *)(lVar1 + 0x38 + uVar5 * 8) =
                (1 << bVar21 ^ 0xffffffffffffffffU) & *(ulong *)(lVar1 + 0x38 + uVar5 * 8);
            uVar3 = *(long *)(lVar1 + 0x18) + uVar3 * *(long *)(lVar2 + 0x48);
            *(long *)(lVar1 + 8) = *(long *)(lVar1 + 8) + 1;
            *(long *)(lVar1 + 0x10) = *(long *)(lVar1 + 0x10) + -1;
            *(long *)(lVar2 + 0x58) = *(long *)(lVar2 + 0x58) + 1;
            *(long *)(lVar2 + 0x60) = *(long *)(lVar2 + 0x60) + -1;
            if (*(long *)(*(long *)(lVar2 + 0x78) + 0x10) != 0)
            {
                return uVar3;
            }
            *(undefined8 *)(lVar2 + 0x78) = 0;
            return uVar3;
        }
        fprintf(stderr, "Corrupted bitmap of zone %s\n", lVar2);
        /* WARNING: Subroutine does not return */
        abort();
    }
    if ((*(long *)(lVar2 + 0x80) != 0) &&
        (*(long *)(*(long *)(lVar2 + 0x80) + 8) + 1U < **(ulong **)(lVar2 + 0x80)))
    {
        local_30 = *(ulong **)(lVar2 + 0x80);
        uVar3 = round_up(*local_30, 0x40);
        pcVar4 = (char *)((long)local_30 + (uVar3 >> 3) + 0x38);
        cVar6 = -(*pcVar4 == (char)cookie._0_8_);
        cVar7 = -(pcVar4[1] == (char)((ulong)cookie._0_8_ >> 8));
        cVar8 = -(pcVar4[2] == (char)((ulong)cookie._0_8_ >> 0x10));
        cVar9 = -(pcVar4[3] == (char)((ulong)cookie._0_8_ >> 0x18));
        cVar10 = -(pcVar4[4] == (char)((ulong)cookie._0_8_ >> 0x20));
        cVar11 = -(pcVar4[5] == (char)((ulong)cookie._0_8_ >> 0x28));
        cVar12 = -(pcVar4[6] == (char)((ulong)cookie._0_8_ >> 0x30));
        cVar13 = -(pcVar4[7] == (char)((ulong)cookie._0_8_ >> 0x38));
        cVar14 = -(pcVar4[8] == (char)cookie._8_8_);
        cVar15 = -(pcVar4[9] == (char)((ulong)cookie._8_8_ >> 8));
        cVar16 = -(pcVar4[10] == (char)((ulong)cookie._8_8_ >> 0x10));
        cVar17 = -(pcVar4[0xb] == (char)((ulong)cookie._8_8_ >> 0x18));
        cVar18 = -(pcVar4[0xc] == (char)((ulong)cookie._8_8_ >> 0x20));
        cVar19 = -(pcVar4[0xd] == (char)((ulong)cookie._8_8_ >> 0x28));
        cVar20 = -(pcVar4[0xe] == (char)((ulong)cookie._8_8_ >> 0x30));
        bVar21 = -(pcVar4[0xf] == (char)((ulong)cookie._8_8_ >> 0x38));
        if ((ushort)((ushort)(SUB161(CONCAT115(bVar21, CONCAT114(cVar20, CONCAT113(cVar19, CONCAT112(cVar18, CONCAT111(cVar17, CONCAT110(cVar16, CONCAT19(cVar15, CONCAT18(cVar14, CONCAT17(cVar13, CONCAT16(cVar12,
                                                                                                                                                                                                             CONCAT15(cVar11, CONCAT14(cVar10, CONCAT13(cVar9,
                                                                                                                                                                                                                                                        CONCAT12(cVar8, CONCAT11(cVar7, cVar6))))))))))))))) >>
                                         7,
                                     0) &
                              1) |
                     (ushort)(SUB161(CONCAT115(bVar21, CONCAT114(cVar20, CONCAT113(cVar19, CONCAT112(cVar18, CONCAT111(cVar17, CONCAT110(cVar16, CONCAT19(cVar15, CONCAT18(cVar14, CONCAT17(cVar13, CONCAT16(cVar12,
                                                                                                                                                                                                             CONCAT15(cVar11, CONCAT14(cVar10, CONCAT13(cVar9,
                                                                                                                                                                                                                                                        CONCAT12(cVar8, CONCAT11(cVar7, cVar6))))))))))))))) >>
                                         0xf,
                                     0) &
                              1)
                         << 1 |
                     (ushort)(SUB141(CONCAT113(bVar21, CONCAT112(cVar20, CONCAT111(cVar19, CONCAT110(cVar18, CONCAT19(cVar17, CONCAT18(cVar16, CONCAT17(cVar15,
                                                                                                                                                        CONCAT16(cVar14, CONCAT15(cVar13, CONCAT14(cVar12,
                                                                                                                                                                                                   CONCAT13(cVar11, CONCAT12(cVar10, CONCAT11(cVar9,
                                                                                                                                                                                                                                              cVar8))))))))))))) >>
                                         7,
                                     0) &
                              1)
                         << 2 |
                     (ushort)(SUB131(CONCAT112(bVar21, CONCAT111(cVar20, CONCAT110(cVar19, CONCAT19(cVar18,
                                                                                                    CONCAT18(cVar17, CONCAT17(cVar16, CONCAT16(cVar15,
                                                                                                                                               CONCAT15(cVar14, CONCAT14(cVar13, CONCAT13(cVar12,
                                                                                                                                                                                          CONCAT12(cVar11, CONCAT11(cVar10, cVar9)))))))))))) >>
                                         7,
                                     0) &
                              1)
                         << 3 |
                     (ushort)(SUB121(CONCAT111(bVar21, CONCAT110(cVar20, CONCAT19(cVar19, CONCAT18(cVar18,
                                                                                                   CONCAT17(cVar17, CONCAT16(cVar16, CONCAT15(cVar15,
                                                                                                                                              CONCAT14(cVar14, CONCAT13(cVar13, CONCAT12(cVar12,
                                                                                                                                                                                         CONCAT11(cVar11, cVar10))))))))))) >>
                                         7,
                                     0) &
                              1)
                         << 4 |
                     (ushort)(SUB111(CONCAT110(bVar21, CONCAT19(cVar20, CONCAT18(cVar19, CONCAT17(
                                                                                             cVar18, CONCAT16(cVar17, CONCAT15(cVar16, CONCAT14(
                                                                                                                                           cVar15, CONCAT13(cVar14, CONCAT12(cVar13, CONCAT11(
                                                                                                                                                                                         cVar12, cVar11)))))))))) >>
                                         7,
                                     0) &
                              1)
                         << 5 |
                     (ushort)((byte)(CONCAT19(bVar21, CONCAT18(cVar20, CONCAT17(cVar19, CONCAT16(cVar18,
                                                                                                 CONCAT15(cVar17, CONCAT14(cVar16, CONCAT13(cVar15,
                                                                                                                                            CONCAT12(cVar14, CONCAT11(cVar13, cVar12))))))))) >>
                                     7) &
                              1)
                         << 6 |
                     (ushort)((byte)(CONCAT18(bVar21, CONCAT17(cVar20, CONCAT16(cVar19, CONCAT15(cVar18,
                                                                                                 CONCAT14(cVar17, CONCAT13(cVar16, CONCAT12(cVar15,
                                                                                                                                            CONCAT11(cVar14, cVar13)))))))) >>
                                     7) &
                              1)
                         << 7 |
                     (ushort)(bVar21 >> 7) << 0xf) != 0xffff)
        {
            fprintf(stderr, "Corrupted `pagep` of zone %s\n", lVar2);
            /* WARNING: Subroutine does not return */
            abort();
        }
        if (local_30[1] + 1 < *local_30)
            goto LAB_0010329c;
    }
    local_30 = (ulong *)map_new_page(*(undefined8 *)(lVar2 + 0x48));
    if (local_30 == (ulong *)0x0)
    {
        fprintf(stderr, "Unable to map address to pagep->base_address for zone %s\n", lVar2);
        /* WARNING: Subroutine does not return */
        abort();
    }
    *(long *)(lVar2 + 0x68) = *(long *)(lVar2 + 0x68) + 1;
    *(ulong *)(lVar2 + 0x50) = *local_30 + *(long *)(lVar2 + 0x50);
    if (*(long *)(lVar2 + 0x70) == 0)
    {
        *(ulong **)(lVar2 + 0x70) = local_30;
        *(undefined8 *)(*(long *)(lVar2 + 0x70) + 0x28) = *(undefined8 *)(lVar2 + 0x70);
        *(undefined8 *)(*(long *)(lVar2 + 0x70) + 0x30) = *(undefined8 *)(lVar2 + 0x70);
    }
    else
    {
        uVar3 = *(ulong *)(*(long *)(lVar2 + 0x70) + 0x30);
        *(ulong **)(uVar3 + 0x28) = local_30;
        local_30[6] = uVar3;
        local_30[5] = *(ulong *)(lVar2 + 0x70);
        *(ulong **)(*(long *)(lVar2 + 0x70) + 0x30) = local_30;
    }
    *(ulong **)(lVar2 + 0x80) = local_30;
LAB_0010329c:
    uVar3 = local_30[4];
    local_30[4] = local_30[4] + *(long *)(lVar2 + 0x48);
    lVar1 = *(long *)(lVar2 + 0x48);
    *(undefined8 *)((uVar3 - 0x10) + lVar1) = cookie._0_8_;
    *(undefined8 *)((uVar3 - 8) + lVar1) = cookie._8_8_;
    local_30[1] = local_30[1] + 1;
    *(long *)(lVar2 + 0x58) = *(long *)(lVar2 + 0x58) + 1;
    return uVar3;
}
