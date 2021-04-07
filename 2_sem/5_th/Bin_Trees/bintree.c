#include "bintree.h"

struct BTree_t *create_node (int data, struct BTree_t* l, struct BTree_t* r)
{
  struct  BTree_t *ret = NULL;

  ret = malloc (sizeof (struct BTree_t ));
  assert (ret);

  ret->left = l;
  ret->right = r;
  ret->data = data;

  return ret;
}

static void lvl_print_tree (const struct BTree_t *top, int lvl)
{
  int i = 0;

  for (i; i < lvl*2; i++)
    printf("%c", ' ');

  printf("%d\n", top->data);
  if (top->left)
    lvl_print_tree (top->left, lvl + 1);
  if (top->right)
    lvl_print_tree (top->right, lvl + 1);
}

void print_tree (const struct BTree_t *top)
{
  assert (top);
  lvl_print_tree (top, 0);
}

// 1100
// *
//  *

// 110010100
// *
//  *
//  *
//   *
static struct BTree_t* reconstruct_tree (int **curtop, int* end)
{
  struct BTree_t *t1, *t2;
  int* cur = *curtop;
  int* nxt = cur + 1;

  assert (cur < end);
  if (*cur == 1)
  {
    t1 = reconstruct_tree (&nxt, end);
    t2 = reconstruct_tree (&nxt, end);
    *curtop = nxt;
    return create_node (1, t1, t2);
  }
  *curtop = nxt;

  return NULL;
}

struct BTree_t* read_zero_one_tree (FILE* f)
{
  assert (f);
  char c;
  int res = 0, nnodes = 0, i = 0;
  int* nodes = NULL, *orig_nodes = NULL;
  struct BTree_t * ret;

  res = fscanf (f, "%d ", &nnodes);
  nnodes = nnodes*2 + 1;
  assert (res == 1);

  nodes = (int*) calloc (nnodes, sizeof (int));
  assert (res);
  orig_nodes = nodes;

  for (i; i < nnodes; i++)
  {
    res = fscanf (f, "%c", &c);
    assert (res == 1);
    assert (c == '0' || c == '1');
    nodes[i] = c - '0';
  }

  ret = reconstruct_tree (&nodes, nodes + nnodes);

  free (orig_nodes);
  return ret;
}

void free_tree (struct BTree_t *top)
{
  int flag = 1;
  struct BTree_t * head = NULL;
  struct BTree_t * prev = NULL;
  head = top;
    while (head->left || head->right)
    {

      while (top->left || top->right)
      {
        if (top->left)
          top = top->left;
        else
          if (top->right)
            top = top->right;
      }
      printf("doshel?\n");
      prev = top->parent;
      printf("data = %d\n", top->data);
      if (prev->right == top)
        prev->right = NULL;
      else
        prev->left = NULL;

      free (top);
      top = prev;

    }
    free (head);
}



// void free_tree (struct BTree_t *top)
// {
//   if (top->left)
//     free_tree (top->left);
//   if (top->right)
//     free_tree (top->right);
//   free (top);
// }
