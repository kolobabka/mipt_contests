#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

unsigned code_movi (unsigned encode);
int read_buf (unsigned* buffer, FILE* inp);


typedef struct regist {
  unsigned opcode;
  int A;
  int B;
  int C;
  int D;
} reg;

void read_instr (int check, const unsigned* buffer, const int len, reg* program);

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

void coder_in (unsigned rx, reg* program)
{
  switch (rx) {
    case A:  
      scanf ("%d", &(program->A)); 
      program->A = program->A % 256; 
      break;
    case B: 
      scanf ("%d", &(program->B)); 
      program->B = program->B % 256; 
      break;
    case C:
      scanf ("%d", &(program->C)); 
      program->C = program->C % 256; 
      break;
    case D: 
      scanf ("%d", &(program->D));
      program->D = program->D % 256; 
      break;
    default:
      printf("ERROR\n"); exit (1);

  }
}

void coder_out (unsigned rx, reg* program)
{

  switch (rx) {
    case A:  
      printf ("%d\n", program->A); 
      break;
    case B: 
      printf ("%d\n", program->B); 
      break;
    case C:
      printf ("%d\n", program->C); 
      break;
    case D: 
      printf ("%d\n", program->D);
      break;
    default:
      printf("ERROR\n"); exit (1);

  }
}

void guess_reg (int encode, reg* program)
{
  unsigned rx = 0u;

  for (int i = 0; i < 2; i++)
  {
    if (((encode >> i) & 1u) == 0)
      rx = rx & ~(1u << i);
    else
      rx = rx | (1u << i);
  }

  if (program->opcode == OUT)
    coder_out (rx, program);
  else if (program->opcode == IN)
    coder_in (rx, program);

}

void coder_div (unsigned registr_1, unsigned registr_2, reg* program)
{
  int ret = 1;

  switch (registr_2) {
    case A:  
      ret = program->A; break;
    case B: 
      ret = program->B; break;
    case C:
      ret = program->C; break;
    case D: 
      ret = program->D; break;
    default:
      printf("ERROR\n"); exit (1);

  }

  switch (registr_1) {
    case A: 
      ret = (program->A / ret) % 256; 
      program->A = ret;
      break;
    case B: 
      ret = (program->B / ret) % 256; 
      program->B = ret;
      break;
    case C:
      ret = (program->C / ret) % 256; 
      program->C = ret;
      break;    
    case D: 
      ret = (program->D / ret) % 256; 
      program->D = ret;
      break;    
    default:
      printf("ERROR\n"); exit (1);

  }

  

  return; 
}

void coder_mul (unsigned registr_1, unsigned registr_2, reg* program)
{
  int ret = 1;

  switch (registr_2) {
    case A:  
      ret = program->A; break;
    case B: 
      ret = program->B; break;
    case C:
      ret = program->C; break;
    case D: 
      ret = program->D; break;
    default:
      printf("ERROR\n"); exit (1);

  }

  switch (registr_1) {
    case A: 
      ret = (program->A * ret) % 256; 
      program->A = ret;
      break;
    case B: 
      ret = (program->B * ret) % 256; 
      program->B = ret;
      break;
    case C:
      ret = (program->C * ret) % 256; 
      program->C = ret;
      break;    
    case D: 
      ret = (program->D * ret) % 256; 
      program->D = ret;
      break;    
    default:
      printf("ERROR\n"); exit (1);

  }

  

  return; 
}

void coder_sub (unsigned registr_1, unsigned registr_2, reg* program)
{
  int ret = 0;

  switch (registr_2) {
    case A:  
      ret = program->A; break;
    case B: 
      ret = program->B; break;
    case C:
      ret = program->C; break;
    case D: 
      ret = program->D; break;
    default:
      printf("ERROR\n"); exit (1);

  }

  switch (registr_1) {
    case A: 
      ret = (program->A - ret) % 256; 
      if (ret < 0)
        ret = 256 + ret;
      program->A = ret;
      break;
    case B: 
      ret = (program->B - ret) % 256; 
      if (ret < 0)
        ret = 256 + ret;
      program->B = ret;
      break;
    case C:
      ret = (program->C - ret) % 256; 
      if (ret < 0)
        ret = 256 + ret;
      program->C = ret;
      break;    
    case D: 
      ret = (program->D - ret) % 256; 
      if (ret < 0)
        ret = 256 + ret;
      program->D = ret;
      break;    
    default:
      printf("ERROR\n"); exit (1);

  }

  

  return; 
}

void coder_add (unsigned registr_1, unsigned registr_2, reg* program)
{
  int ret = 0;

  // printf ("reg = %d\n", reg);
  // printf ("D = %d\n", D);
  switch (registr_2) {
    case A: 
      ret = (ret + program->A) % 256; break;
    case B: 
      ret = (ret + program->B) % 256; break;
    case C:
      ret = (ret + program->C) % 256; break;
    case D: 
      ret = (ret + program->D) % 256; break;
    default:
      printf("ERROR\n"); exit (1);

  }

  switch (registr_1) {
    case A: 
      ret = (ret + program->A) % 256; 
      program->A = ret;
      break;
    case B: 
      ret = (ret + program->B) % 256; 
      program->B = ret;
      break;
    case C:
      ret = (ret + program->C) % 256; 
      program->C = ret;
      break;    
    case D: 
      ret = (ret + program->D) % 256; 
      program->D = ret;
      break;    
    default:
      printf("ERROR\n"); exit (1);

  }

  

  return; 
}
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
void code_reg (int encode, reg* program)
{
  unsigned rx = 0u;
  unsigned rs = 0u;

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

  if (program->opcode == ADD)
    coder_add (rs, rx, program);
  else if (program->opcode == SUB)
    coder_sub (rs, rx, program);
  else if (program->opcode == MUL)
    coder_mul (rs, rx, program);
  else if (program->opcode == DIV)
    coder_div (rs, rx, program);

  // printf ("\nProgram->A = %d\n", program->A);
  // printf ("Program->B = %d\n", program->B);
  // printf ("Program->C = %d\n", program->C);
  // printf ("Program->D = %d\n", program->D);
  //printf ("%c, %c\n", reg_2, reg_1);

}
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------

unsigned code_movi (unsigned encode)
{
  unsigned num = 0u;

  for (int i = 0; i < 7; i++)
  {
    if (((encode >> i) & 1u) == 0)
      num = num & ~(1u << i);
    else
      num = num | (1u << i);
  }

  return num;
}
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
void read_instr (int check, const unsigned* buffer, const int len, reg* program)
{
  int res = 0;
  unsigned encode = 0u;
  unsigned tmp = 0u;

  encode = buffer[check];

  for (int i = 0; i < 4; i++)
  {
    if (((encode >> 4 + i) & 1u) == 0)
      tmp = tmp & ~(1u << i);
    else
      tmp = tmp | (1u << i);

    //printf ("%d ", val[i]);
  }

  if (encode >= 0xc8)
  {
    printf("ERROR\n"); exit (1);
  }
  else if (tmp < 0x8 && tmp >= 0x0)
  {
    //printf ("MOVI ");
    program->opcode = MOVI;
    program->D = code_movi (encode);
    //code_movi (encode);
    //printf ("\nD = %d\n", program->D);
  }
  else if (tmp == 0x8)
  {
    //printf ("ADD ");
    program->opcode = ADD;
    code_reg (encode, program);
  }
  else if (tmp == 0x9)
  {
    //printf ("SUB ");
    program->opcode = SUB;
    code_reg (encode, program);
  }
  else if (tmp == 0xA)
  {
    //printf ("MUL ");
    program->opcode = MUL;
    code_reg (encode, program);
  }
  else if (tmp == 0xB)
  {
    //printf ("DIV ");
    program->opcode = DIV;
    code_reg (encode, program);
  }
  else if (tmp == 0xC)
  {
    
    if ( ( (encode >> 2) & 1u ) == 1)
    {
      //printf ("OUT ");
      program->opcode = OUT;
      guess_reg (encode, program);
    }
    else
    {
      //printf ("IN ");
      program->opcode = IN;
      guess_reg (encode, program);
    }
  }
  else
  {
    printf("ERROR\n"); exit (1);
  }
  
  

  return;
}
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
int read_buf (unsigned* buffer, FILE* inp)
{
  int check = 1;
  int counter = 0;

  while (check == 1)
  {
    check = fscanf (inp, "%x", buffer + counter);
    if (check != 1)
      break;
    counter++;
  }

  return counter;
}
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
int main (int argc, char** argv)
{

  int check = 0;
  int len = 0;
  unsigned buffer[100000] = {0};
  FILE* inp = NULL;
  reg program = {0, 0, 0, 0, 0}; 

  if (argc < 2)
  {
    printf("Usage: <%sfile-to-open\n", argv[0]);
    return -1;
  }

  inp = fopen (argv[1], "r");

  if (inp == NULL)
  {
    perror ("File open error:");
    return -2;
  }

  len = read_buf (buffer, inp); 

  // for (int i = 0; i < len; i++)
  //   printf ("0x%X ", *(buffer + i));
  while (check < len)
  {
    read_instr (check, buffer, len, &program);
    check++;
  }
  fclose (inp);
}