#pragma once

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

void read_instr (int* check, const unsigned* buffer, const int len, reg* program);

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