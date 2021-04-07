#pragma once

struct BTree_t {
  struct BTree_t *left;
  struct BTree_t *right;
  int data;
};
ы
struct BTree_t *create_node (int data, struct BTree_t *l, struct BTree_t *r);

struct BTree_t * read_zero_one_tree (FILE* f);

//void print_tree (const struct BTree_t *top);

void free_tree (struct BTree_t *top);

void print_edge (const struct BTree_t *top);
