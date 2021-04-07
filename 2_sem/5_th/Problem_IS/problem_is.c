#include <limits.h>

int check (struct tree_t * top, int left, int right);

int check_is_bst(struct tree_t *top)
{
  int res = 0;
  res = check (top, INT_MIN, INT_MAX);

  return res;
}

int check (struct tree_t * top, int left, int right)
{
  int res = 1;

  if (top->data < left || top->data > right)
    return 0;

  if (top->left)
  {
    res *= check (top->left, left, top->data);
  }
  if (top->right)
  {
    res *= check (top->right, top->data, right);
  }

  return res;
}
