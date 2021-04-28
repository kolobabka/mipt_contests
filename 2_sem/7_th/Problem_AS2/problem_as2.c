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
  struct { 
    int rd, rs;
  } ops;
  int rop;
};

struct instr_t {
  enum opcode_t opcode;
  union operand_t opnd;
};

struct reg_state_t {
  unsigned char data;
  unsigned char init;
  // ???
};
//..............................................................................
//..............................................................................

char coder (unsigned reg)
{
  char ret;

  // printf ("reg = %d\n", reg);
  // printf ("D = %d\n", D);
  switch (reg) {
    case A: 
      ret = 'A'; break;
    case B: 
      ret = 'B'; break;
    case C:
      ret = 'C'; break;
    case D: 
      ret = 'D'; break;
    default:
      printf("ERROR\n"); exit (1);

  }
  return ret; 
}

void code_in_out (unsigned encode)
{
  unsigned rs = 0u;

  char reg_1 = '0';

  for (int i = 0; i < 2; i++)
  {
    
    if (((encode >> i) & 1u) == 0)
      rs = rs & ~(1u << i);
    else
      rs = rs | (1u << i);
  }

  reg_1 = coder (rs);

  printf ("%c\n", reg_1);
}

void code_movi (unsigned encode)
{
  unsigned num = 0u;

  for (int i = 0; i < 7; i++)
  {
    if (((encode >> i) & 1u) == 0)
      num = num & ~(1u << i);
    else
      num = num | (1u << i);
  }

  printf ("%d\n", num);
}

void code_reg (int encode)
{
  unsigned rx = 0u;
  unsigned rs = 0u;

  char reg_1 = '0';
  char reg_2 = '0';

  for (int i = 0; i < 2; i++)
  {
    if (((encode >> i) & 1u) == 0)
      rx = rx & ~(1u << i);
    else
      rx = rx | (1u << i);

    if (((encode >> 2 + i) & 1u) == 0)
      rs = rs & ~(1u << i);
    else
      rs = rs | (1u << i);
  }

  reg_1 = coder (rx);
  reg_2 = coder (rs);

  printf ("%c, %c\n", reg_2, reg_1);

}

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
//..............................................................................
//..............................................................................
//..............................................................................
//..............................................................................
//..............................................................................
//..............................................................................
//..............................................................................
//..............................................................................
void read_instr (int* check)
{
  int res = 0;
  unsigned encode = 0u;
  unsigned tmp = 0u;
  int val[4] = {0};

  res = scanf ("%x", &encode);
  if (res != 1)
  {
    *check = 1;
    return ;
  }

  for (int i = 0; i < 4; i++)
  {
    val[i] = ((encode >> 4 + i) & 1u);
    if (((encode >> 4 + i) & 1u) == 0)
      tmp = tmp & ~(1u << i);
    else
      tmp = tmp | (1u << i);

    //printf ("%d ", val[i]);
  }

  if (tmp < 0x8 && tmp >= 0x0)
  {
    printf ("MOVI ");

    code_movi (encode);
  }
  else if (tmp == 0x8)
  {
    printf ("ADD ");

    code_reg (encode);
  }
  else if (tmp == 0x9)
  {
    printf ("SUB ");
    code_reg (encode);
  }
  else if (tmp == 0xA)
  {
    printf ("MUL ");
    code_reg (encode);
  }
  else if (tmp == 0xB)
  {
    printf ("DIV ");
    code_reg (encode);
  }
  else if (tmp == 0xC)
  {
    
    if ( ( (encode >> 2) & 1u ) == 1)
    {
      printf ("OUT ");
      code_in_out (encode);
    }
    else
    {
      printf ("IN ");
      code_in_out (encode);
    }
  }
  else
  {
    printf("ERROR\n"); exit (1);
  }
  
  

  return;
}
//..............................................................................
//..............................................................................
//..............................................................................
//..............................................................................
int main ()
{
  int check = 0; 
  while (!check)
  {
    unsigned code = 0;   
    struct instr_t instr;
    read_instr (&check);

    if (check) 
      break;

    //code = encode_instr (instr);
  }
  //code = encode_instr (instr);

  //printf("0x%x ", code);

}