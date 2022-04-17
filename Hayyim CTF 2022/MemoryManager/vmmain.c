/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vmmain(VM *vm)

{
  long lVar1;
  byte opcode;
  ushort op2;
  ushort op1;
  long in_FS_OFFSET;
  ulong v1;
  ulong v2;
  undefined2 dst;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  dst = 0;
  v1 = 0;
  v2 = 0;
  while( true ) {
    opcode = fetch_opcode(vm);
    switch(opcode) {
    case 0:
    case 3:
      op1 = get_operand(vm);
      op2 = get_operand(vm);
      dst = op1 & 0xff | op2 << 8;
      break;
    case 1:
    case 2:
      op1 = get_operand(vm);
      dst = dst & 0xff00 | op1 & 0xff;
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      op1 = get_operand(vm);
      op2 = get_operand(vm);
      dst = op1 & 0xff | op2 << 8;
      op1 = get_operand(vm);
      v1 = read_value(vm,op2 & 0xff);
      v2 = read_value(vm,op1 & 0xff);
      break;
    case 8:
      op1 = get_operand(vm);
      dst = dst & 0xff00 | op1 & 0xff;
    }
    if (9 < opcode) break;
    switch(opcode) {
    case 0:
      v1 = read_value(vm,(ushort)dst._1_1_);
      write_value(vm,dst & 0xff,v1);
      break;
    case 1:
      v1 = read_value(vm,dst & 0xff);
      write_value(vm,0x10,v1);
      break;
    case 2:
      v1 = read_value(vm,0x10);
      write_value(vm,dst & 0xff,v1);
      break;
    case 3:
      DAT_004050ac = 0;
      v1 = read_value(vm,dst & 0xff);
      DAT_004050ac = 1;
      v2 = read_value(vm,(ushort)dst._1_1_);
      FUN_00401909(vm,dst & 0xff,(ushort)dst._1_1_,v1,v2);
      DAT_004050ac = 0xffffffff;
      _DAT_004050d0 = 0;
      _DAT_004050d8 = 0;
      _DAT_004050c0 = 0;
      _DAT_004050c8 = 0;
      break;
    case 4:
      write_value(vm,dst & 0xff,v1 + v2);
      break;
    case 5:
      write_value(vm,dst & 0xff,v1 - v2);
      break;
    case 6:
      write_value(vm,dst & 0xff,v1 * v2);
      break;
    case 7:
      write_value(vm,dst & 0xff,v1 / v2);
      break;
    case 8:
      debug(vm,dst & 0xff);
      break;
    case 9:
      if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  exit(-1);
}