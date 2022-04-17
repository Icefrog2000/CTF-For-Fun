typedef struct {
  
  u64 pc; // +58h
} VM;

u8 fetch(VM *regs) {
  u8 opcode = opCodes[regs->pc];
  if (++opCodes[regs->pc] >= 0x1000) exit(-1);
  return opcode;
}

u16 GetOperand(VM *regs) {
  u16 val = ((u16*)opCodes)[regs->pc];
  if (regs->pc + 2 >= opMaxSize) exit(-1);
  regs->pc += 2;
  return val;
}

void RunVM(VM *regs) {
  u8 opcode = fetch(regs);
  u8 op1, op2, op3;

  switch (opcode) {
    case 0:
      op1 = (u8)GetOperand(regs);
      op2 = (u8)GetOperand(regs);
      break;
    case 1:
    case 2:
    case 7:
      op1 = (u8)GetOperand(regs);
      break;
    case 3:
    case 4:
    case 5:
    case 6:
      op1 = (u8)GetOperand(regs);
      op2 = (u8)GetOperand(regs);
      op3 = (u8)GetOperand(regs);
      r1 = X(regs, op2);
      r2 = X(regs, op3);
      break;
  }

  switch (opcode) {
    case 0:
      r1 = X(regs, op2);
      X(regs, op1, r1);
  }
}
