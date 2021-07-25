#pragma once

#include "problem_lx.h"

enum node_kind_t {
  NODE_OP,
  NODE_VAL
};

struct node_data_t {
  enum node_kind_t k;
  union {
    enum operation_t op;
    int d;
  } u;
};

struct node_t {
  struct node_t* left;
  struct node_t* right;
  struct node_t* parent;
  struct node_data_t data;
  int res;
};

struct node_t* build_syntax_tree (struct lex_array_t lexarr);
struct node_t* Par_Expr (struct lex_array_t lexarr);
struct node_t* Par_Mult (struct lex_array_t lexarr);
struct node_t* Par_Term (struct lex_array_t lexarr);

void Print_Node (struct node_t* node);
void Print_Tree (struct node_t* top);
int calc_result (struct node_t* top);

void free_syntax_tree (struct node_t* top);
