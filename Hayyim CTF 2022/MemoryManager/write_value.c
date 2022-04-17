/* 1|0 -> push
   2|X -> read X bytes from bytecodes as offset, then read more 1 byte from bytecodes as size and
   (size*)MEM[offset] = value
   3|X -> save to regeister (X == 0 -> ax, X == 1 -> bx, ...) */

void write_value(VM *vm,ushort kind,long value)

{
  byte bVar1;
  ushort uVar2;
  ulong memidx;
  
  if ((kind & 0xf0) == 0x10) {
    if (vm->rsp < 8) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    vm->rsp = vm->rsp - 8;
    *(long *)((long)stackptr + vm->rsp) = value;
  }
  else {
    if ((kind & 0xf0) == 0x20) {
      bVar1 = (byte)kind & 0xf;
      if (bVar1 == 1) {
        bVar1 = fetch_opcode(vm);
        memidx = (ulong)bVar1;
      }
      else {
        if (bVar1 == 2) {
          uVar2 = get_operand(vm);
          memidx = (ulong)uVar2;
        }
        else {
          if (bVar1 == 4) {
            memidx = get_int(vm);
            memidx = memidx & 0xffffffff;
          }
          else {
            if (bVar1 != 8) {
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            memidx = get_long(vm);
          }
        }
      }
      if (CODE_LEN - 8U <= memidx) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      bVar1 = fetch_opcode(vm);
      if (bVar1 == 1) {
        *(undefined *)(memidx + MEM) = (char)value;
      }
      else {
        if (bVar1 == 2) {
          *(undefined2 *)(memidx + MEM) = (short)value;
        }
        else {
          if (bVar1 == 4) {
            *(undefined4 *)(memidx + MEM) = (int)value;
          }
          else {
            if (bVar1 != 8) {
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            *(long *)(MEM + memidx) = value;
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
        (&vm->ax)[(uint)kind & 0xf] = value;
      }
    }
  }
  return;
}