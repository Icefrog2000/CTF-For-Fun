/* 1|0 -> pop
   2|X -> read X bytes as offset from bytecode, then read value size from bytecode and return
   MEM[offset]
   3|X -> read from register (X is register type)
   4|X -> read X bytes from bytecode and return */

ulong read_value(VM *vm,ushort kind)

{
  byte size;
  ushort uVar1;
  ulong ret;
  ulong x;
  
                    /* pop */
  if ((kind & 0xf0) == 0x10) {
    if (vm->rsp == vm->rbp) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    ret = *(ulong *)(vm->rsp + (long)stackptr);
    vm->rsp = vm->rsp + 8;
  }
  else {
                    /* 0x2X
                       X is datasize (1,2,4,...) */
    if ((kind & 0xf0) == 0x20) {
      kind = kind & 0xf;
      if (kind == 1) {
        size = fetch_opcode(vm);
        x = (ulong)size;
      }
      else {
        if (kind == 2) {
          uVar1 = get_operand(vm);
          x = (ulong)uVar1;
        }
        else {
          if (kind == 4) {
            x = get_int(vm);
            x = x & 0xffffffff;
          }
          else {
            if (kind != 8) {
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            x = get_long(vm);
          }
        }
      }
      if (DAT_004050ac != -1) {
        *(ulong *)(&DAT_004050d0 + (long)DAT_004050ac * 8) = x;
      }
      size = fetch_opcode(vm);
      if (DAT_004050ac != -1) {
        *(ulong *)(&DAT_004050c0 + (long)DAT_004050ac * 8) = (ulong)size;
      }
      if (size == 1) {
        ret = (ulong)*(byte *)(x + MEM);
      }
      else {
        if (size == 2) {
          ret = (ulong)*(ushort *)(x + MEM);
        }
        else {
          if (size == 4) {
            ret = (ulong)*(uint *)(x + MEM);
          }
          else {
            if (size != 8) {
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            ret = *(ulong *)(x + MEM);
          }
        }
      }
    }
    else {
      if ((kind & 0xf0) == 0x30) {
        if (5 < (kind & 0xf)) {
                    /* WARNING: Subroutine does not return */
          exit(-1);
        }
        ret = (&vm->ax)[(uint)kind & 0xf];
      }
      else {
        if ((kind & 0xf0) != 0x40) {
                    /* WARNING: Subroutine does not return */
          exit(-1);
        }
        kind = kind & 0xf;
        if (kind == 1) {
          size = fetch_opcode(vm);
          ret = (ulong)size;
        }
        else {
          if (kind == 2) {
            uVar1 = get_operand(vm);
            ret = (ulong)uVar1;
          }
          else {
            if (kind == 4) {
              ret = get_int(vm);
              ret = ret & 0xffffffff;
            }
            else {
              if (kind != 8) {
                    /* WARNING: Subroutine does not return */
                exit(-1);
              }
              ret = get_long(vm);
            }
          }
        }
      }
    }
  }
  return ret;
}