//..............................................................................
//..............................................................................
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

enum reg_t {
  A = 0, B, C, D, RLAST
};

enum opcode_t {
  MOVI = 0, ADD = 8, SUB = 9, MUL = 10, DIV = 11, IN = 48, OUT = 49, OPLAST
};

union operand_t {
  struct { int rd, rs; } ops;
  int rop;
};

struct instr_t {
  enum opcode_t opcode;
  union operand_t opnd;
};

struct reg_state_t {
  unsigned char data;
  unsigned char init;
};
//..............................................................................
//..............................................................................
union operand_t push_movi ()
{
  int res = 0;
  int rx = 0;
  union operand_t opnd;

  res = scanf ("%d", &rx);
  assert (res == 1);

  opnd.rop = rx;

  return opnd;
}
//..............................................................................
//..............................................................................
enum reg_t decode_reg (char c)
{
  enum reg_t ret;
  switch (c) {
    case 'A': ret = A; break;
    case 'B': ret = B; break;
    case 'C': ret = C; break;
    case 'D': ret = D; break;
    default:
      printf("ERROR\n"); exit (1);
  }
  return ret;
}
//..............................................................................
//..............................................................................
union operand_t read_arith_opnd ()
{
  int res = 0;
  char rx = 0, rs = 0;
  union operand_t opnd;

  res = scanf ("%c, %c", &rx, &rs);
  assert (res == 2);

  //printf("arith: %c, %c\n", rx, rs);
  opnd.ops.rd = decode_reg (rx);
  opnd.ops.rs = decode_reg (rs);

  return opnd;
}
//..............................................................................
//..............................................................................
union operand_t push_in_out ()
{
  int res = 0;
  char rs = 0;
  union operand_t opnd;

  res = scanf ("%c ", &rs);
  assert (res == 1);

  //printf("reg_in: %c\n", rs);
  //opnd.ops.rd = decode_reg ('A');
  opnd.rop = decode_reg (rs);

  return opnd;
}
//..............................................................................
//..............................................................................
//..............................................................................
//..............................................................................
struct instr_t read_instr (int* check)
{
  struct instr_t instr;
  int res = 0;
  char mnem[64];

  res = scanf ("%s ", mnem);
  if (res != 1)
  {
    *check = 1;
    return instr;
  }

  //printf("mnem: %s\n", mnem);

  if (!strcmp (mnem ,"ADD"))
  {
    instr.opcode = ADD;
    instr.opnd = read_arith_opnd ();
  }
  else if (!strcmp (mnem ,"MUL"))
  {
    instr.opcode = MUL;
    instr.opnd = read_arith_opnd ();
  }
  else if (!strcmp (mnem ,"SUB"))
  {
    instr.opcode = SUB;
    instr.opnd = read_arith_opnd ();
  }
  else if (!strcmp (mnem ,"DIV"))
  {
    instr.opcode = DIV;
    instr.opnd = read_arith_opnd ();
  }
  else if (!strcmp (mnem ,"IN"))
  {
    instr.opcode = IN;
    instr.opnd = push_in_out ();
  }
  else if (!strcmp (mnem ,"OUT"))
  {
    instr.opcode = OUT;
    instr.opnd = push_in_out ();
  }
  else if (!strcmp (mnem ,"MOVI"))
  {
    instr.opcode = MOVI;
    instr.opnd = push_movi ();
  }
  else
  {
    printf("ERROR\n"); exit (1);
  }

  return instr;
}
//..............................................................................
//..............................................................................
unsigned encode_instr (struct instr_t instr)
{
  unsigned code = 0;
  switch (instr.opcode) {
    case ADD:
    case SUB:
    case MUL:
    case DIV:
      code = code | (instr.opcode << 4) | (instr.opnd.ops.rd << 2) | (instr.opnd.ops.rs);
      break;
    case IN:
    case OUT:
      code = code | (instr.opcode << 2) | (instr.opnd.rop);
    case MOVI:
      code = code | (instr.opnd.rop);
      break;
    default:
      printf("ERROR\n"); exit (1);
  }
  return code;
}
//..............................................................................
//..............................................................................
int main ()
{
  int check = 0;
  while (!check)
  {
    unsigned code = 0;
    struct instr_t instr;
    instr = read_instr (&check);
    if (check) 
      break;
    code = encode_instr (instr);

    printf("0x%x ", code);
  }

}
