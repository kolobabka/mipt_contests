#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//..............................................................................
typedef struct BTree_t {
  struct BTree_t *left;
  struct BTree_t *right;
  int data;
} tree;
//..............................................................................
void Fill_Arr (int* arr, int num);
tree* Construct_Tree (tree* b_tree, int* arr, int num);
void lvl_print_tree (const struct BTree_t *top, int lvl);
void topology_tree (const struct BTree_t *top, int num);
void free_tree (struct BTree_t *top);
void data_tree (const struct BTree_t *top, int num);
//..............................................................................
int global = 0;
//..............................................................................
int main ()
{
  int check = 666;
  int* arr = NULL;
  tree* b_tree = NULL;
  int num = 0;
  int* topology = NULL;

  check = scanf ("%d", &num);
  assert (check == 1);

  arr = (int*) calloc (num, sizeof (int));
  assert (arr);

  topology = (int*) calloc ((num*2) + 1, sizeof (int));
  assert (topology);

  Fill_Arr (arr, num);

  b_tree = (tree*) calloc (1, sizeof (tree));
  assert (b_tree);

  b_tree = Construct_Tree (b_tree, arr, num);

  printf("%d\n", num);
  printf("%d ", 1);
  topology_tree (b_tree, num);
  printf("\n");
  data_tree (b_tree, num);

  free_tree (b_tree);
  free (arr);
  free (topology);
}

void Fill_Arr (int* arr, int num)
{
  int check = 0;
  assert (arr);

  for (int i = 0; i < num; i++)
  {
    check = scanf ("%d", arr + i);
    assert (check == 1);
  }
}
//..............................................................................
tree* Construct_Tree (tree* b_tree, int* arr, int num)
{
  tree* cur = NULL;
  int counter = 1;
  assert (b_tree);
  assert (arr);

  b_tree->data = arr[0];
  cur = b_tree;

  while (counter < num)
  {
    if (arr[counter] <= cur->data)
    {
      if (cur->left)
      {
        cur = cur->left;
        continue;
      }
      else
      {
        cur->left = (tree*) calloc (1, sizeof (tree));
        cur = cur->left;
        cur->data = arr[counter];
        cur = b_tree;
        counter++;
        continue;
      }
    }
    if (arr[counter] >= cur->data)
    {

      if (cur->right)
      {
        cur = cur->right;
        continue;
      }
      else
      {
        cur->right = (tree*) calloc (1, sizeof (tree));
        cur = cur->right;
        cur->data = arr[counter];
        cur = b_tree;
        counter++;
        continue;
      }

    }
  }
  return b_tree;
}

void free_tree (struct BTree_t *top)
{
  if (top->left)
    free_tree (top->left);
  if (top->right)
    free_tree (top->right);
  free (top);
}

void topology_tree (const struct BTree_t *top, int num)
{
  if (top->left)
  {
    printf("%d ", 1);
    topology_tree (top->left, num);
  }
  else
  {
    if (global < num )
    {
      printf("%d ", 0);
      global++;
    }
  }

  if (top->right)
  {
    printf("%d ", 1);
    topology_tree (top->right, num);
  }
  else
  {
    if (global < num )
    {
      printf("%d ", 0);
      global++;
    }
  }

}

void data_tree (const struct BTree_t *top, int num)
{
  printf("%d ", top->data);
  if (top->left)
  {

    global++;
    data_tree (top->left, num);
  }

  if (top->right)
  {
    global++;
    data_tree (top->right, num);
  }

}
