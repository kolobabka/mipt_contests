#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "bin_trees.h"


struct BTree_t * reconstruct_tree (int** curtop, int *end)
{
  int *cur = *curtop;
  int *nxt = cur + 1;
  assert (cur < end);
  if (*cur == 1)
  {
    struct BTree_t *t1, *t2;
    t1 = reconstruct_tree(&nxt, end);
    t2 = reconstruct_tree(&nxt, end);
    *curtop = nxt;
    return create_node(1, t1, t2);
  }
  *curtop = nxt;
  return NULL;
}
struct BTree_t *create_node (int data, struct BTree_t *l, struct BTree_t *r)
{
  struct BTree_t *ret = malloc (sizeof(struct BTree_t));
  assert (ret);

  ret->left = l;
  ret->right = r;
  ret->data = data;

  return ret;
}

void print_edge (const struct BTree_t *top)
{
  assert (top);

  if (top->left != NULL)
  {
    printf("%d %d ",top->data, top->left->data);

    print_edge (top->left);
  }

  if (top->right != NULL)
  {
    printf("%d %d ",top->data, top->right->data);

    print_edge (top->right);
  }
}

void free_tree (struct BTree_t *top)
{
  assert (top);
  if (top->left)
    free_tree (top->left);
  if (top->right)
    free_tree (top->right);
  free(top);
}

struct BTree_t * read_zero_one_tree (FILE* f)
{
  char c;
  int res;
  int nnodes, i;
  int* nodes;
  assert (f);

  res = fscanf (f, "%d", &nnodes);
  assert (res == 1);

  nodes = (int*) calloc (nnodes, sizeof(int));
  assert (nodes);

  for (i = 0; i < nnodes; i++)
  {
    res = fscanf (f, "%c", &c);
    assert (res == 1);
    assert (c == '0' || c == '1');
    nodes[i] = c - '0';
  }

  return reconstruct_tree (nodes, nnodes + nodes);
}
