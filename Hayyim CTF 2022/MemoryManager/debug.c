void debug(VM *vm,ushort param_2)

{
  byte bVar1;
  ushort uVar2;
  ulong local_18;
  ulong local_10;
  
  if ((param_2 & 0xf0) == 0x10) {
    printf("RSP: %llu\n, RBP: %llu\n",vm->rsp,vm->rbp);
    printf("STACK[%llu]: %llu\n",vm->rsp,*(undefined8 *)(vm->rsp + (long)stackptr));
  }
  else {
    if ((param_2 & 0xf0) == 0x20) {
      if ((param_2 & 0xf) == 1) {
        bVar1 = fetch_opcode(vm);
        local_10 = (ulong)bVar1;
        local_18 = (ulong)*(byte *)(local_10 + MEM);
      }
      else {
        if ((param_2 & 0xf) == 2) {
          uVar2 = get_operand(vm);
          local_10 = (ulong)uVar2;
          if ((ulong)CODE_LEN <= local_10) {
                    /* WARNING: Subroutine does not return */
            exit(-1);
          }
          local_18 = (ulong)*(ushort *)(local_10 + MEM);
        }
        else {
          if ((param_2 & 0xf) == 4) {
            local_10 = get_int(vm);
            local_10 = local_10 & 0xffffffff;
            if ((ulong)CODE_LEN <= local_10) {
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            local_18 = (ulong)*(uint *)(local_10 + MEM);
          }
          else {
            if ((param_2 & 0xf) != 8) {
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            local_10 = get_long(vm);
            if ((ulong)CODE_LEN <= local_10) {
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            local_18 = *(ulong *)(local_10 + MEM);
          }
        }
      }
      printf("DATA[%llu]: %llu\n",local_10,local_18);
    }
    else {
      if ((param_2 & 0xf0) != 0x30) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      printf("AX: %llu\n",vm->ax);
      printf("BX: %llu\n",vm->bx);
      printf("CX: %llu\n",vm->cx);
      printf("DX: %llu\n",vm->dx);
      printf("SI: %llu\n",vm->si);
      printf("DI: %llu\n",vm->di);
      printf("BP: %llu\n",vm->rbp);
      printf("SP: %llu\n",vm->rsp);
      printf("PC: %llu\n",vm->pc);
    }
  }
  return;
}