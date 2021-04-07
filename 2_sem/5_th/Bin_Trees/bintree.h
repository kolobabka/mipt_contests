#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#pragma once


struct BTree_t {
  struct BTree_t* right;
  struct BTree_t* left;
  struct BTree_t* parent;
  int data;
};

struct BTree_t *create_node (int data, struct BTree_t* l, struct BTree_t* r);
void free_tree (struct BTree_t *top);
void print_tree (const struct BTree_t* top);
struct BTree_t* read_zero_one_tree (FILE* f);
