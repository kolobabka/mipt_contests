//..............................................................................
//..............................................................................
#include "problem_mk.h"
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

  printf("arith: %c, %c\n", rx, rs);
  opnd.ops.rd = decode_reg (rx);
  opnd.ops.rs = decode_reg (rs);

  return opnd;
}
//..............................................................................
//..............................................................................
union operand_t push_in ()
{
  int res = 0;
  char rs = 0;
  union operand_t opnd;

  res = scanf ("%c ", &rs);
  assert (res == 1);

  printf("reg_in: %c\n", rs);
  //opnd.ops.rd = decode_reg ('A');
  opnd.ops.rs = decode_reg (rs);

  return opnd;
}
//..............................................................................
//..............................................................................
union operand_t push_out ()
{
  int res = 0;
  char rs = 0;
  union operand_t opnd;

  res = scanf ("%c, ", &rs);
  assert (res == 1);

  printf("reg_out: %c\n", rs);
  opnd.ops.rd = decode_reg ('B');
  opnd.ops.rs = decode_reg (rs);

  return opnd;
}
//..............................................................................
//..............................................................................
struct instr_t read_instr ()
{
  struct instr_t instr;
  int res = 0;
  char mnem[64];


  res = scanf ("%s ", mnem);
  assert (res == 1);

  printf("mnem: %s\n", mnem);

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
    instr.opnd = push_in ();
  }
  else if (!strcmp (mnem ,"OUT"))
  {
    instr.opcode = OUT;
    instr.opnd = push_out ();
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
      code = code | (instr.opcode << 4)
                  | (instr.opnd.ops.rd << 2)
                  | (instr.opnd.ops.rs);
      break;
    case IN:
      code = code | (instr.opcode << 4)
                  | (instr.opnd.ops.rs);
      break;
    case OUT:
      code = code | (instr.opcode << 4)
                  | (instr.opnd.ops.rd << 2)
                  | (instr.opnd.ops.rs);
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
  unsigned code = 0;
  struct instr_t instr;
  instr = read_instr ();
  code = encode_instr (instr);

  printf("%x\n", code);

}
