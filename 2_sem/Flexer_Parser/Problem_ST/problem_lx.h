#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// lexem is operation | brace | number
enum lexem_kind_t {
  OP    = 0,
  BRACE = 1,
  NUM   = 2
};

// operation is: +, -, *, /
enum operation_t {
  ADD = 0,
  SUB = 1,
  MUL = 2,
  DIV = 3
};

// braces are: (, )
enum braces_t {
  LBRAC = 0,
  RBRAC = 1
};

// lexem is one of lexem kind entities
// if (l.kind == BRACE)
//   assert(l.lex.b == LBRAC || l.lex.b == RBRAC)
struct lexem_t {
  enum lexem_kind_t kind;
  union {
    enum operation_t op;
    enum braces_t b;
    int num;
  } lex;
};

// array of lexems
// size: actual number of elements
// capacity: number of additions before realloc
struct lex_array_t {
  struct lexem_t *lexems;
  int capacity;
  int size;
};

// initial capacity
enum {
  ICAP = 10
};

// string to lexem array: see Problem LX on slides
struct lex_array_t lex_string (const char *str);

// printing
void print_lexem (struct lexem_t lxm);
void dump_lexarray (struct lex_array_t pl);
