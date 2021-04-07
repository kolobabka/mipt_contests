#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct BTree_t {
  int left;
  int right;

  struct BTree_t* left_child;
  struct BTree_t* right_child;

};

int global = 0;

int Return_tree (int* in_order, int* pre_order, int pre_index, int in_index, struct BTree_t* node, int pre_predok, int number);
// void Return_tree (int* in_order, int* pre_order, int index_pre, int number);
void Fill_arr (int* nodes, int number);
void Print_arr (const int* arr, int number);
int Find_left (int* in_order, int* pre_order, int index_pre, int number);
int Find_right (int* in_order, int* pre_order, int index_pre, int number);
int Find_root (int i, int* in_order, int* pre_order, int number);
void Print_Res (const struct BTree_t* node, int index, int number);

int main ()
{
  int number = 0;
  int j = 0, i = 0;
  int* pre_order = NULL;
  int* in_order = NULL;
  int pre_index = 0, in_index = 0;
  int check = 0;
  int pre_predok = 0;
  //FILE* inp;
  struct BTree_t* node = NULL;
  struct BTree_t* tree = NULL;

  pre_index = 0;

  // if (argc < 2)
  // {
  //   printf("Usage: <%sfile-to-open\n", argv[0]);
  //   return -1;
  // }
  //
  // inp = fopen (argv[1], "r");
  //
  // if (inp == NULL)
  // {
  //   perror ("File open error:");
  //   return -2;
  // }

  check = scanf("%d", &number);
  assert (check == 1);

  pre_order = (int*) calloc (number, sizeof (int));
  assert (pre_order);

  in_order = (int*) calloc (number, sizeof (int));
  assert (in_order);

  node = (struct BTree_t*) calloc (number, sizeof (struct BTree_t));

  Fill_arr (pre_order, number);
  Fill_arr (in_order, number);

  in_index = Find_root (0, in_order, pre_order, number);

  Return_tree (in_order, pre_order, pre_index, in_index, node, in_index, number);

  // for (int i = 0; i < number; i++)
  // {
  //   printf("i = %d\n", i);
  //   printf("left = %d\n", node[i].left);
  //   printf("right = %d\n", node[i].right);
  // }
  printf("%d\n", number);
  printf("%d ", 1);
  Print_Res (node, pre_order[0], number);
  printf("\n");
  Print_arr (pre_order, number);

  free (pre_order);
  free (in_order);
  free (node);

  //fclose (inp);
}

void Fill_arr (int* nodes, int number)
{
  int check = 0;
  assert (nodes);

  for (int i = 0; i < number; i++)
  {
    check = scanf ("%d", nodes + i);
    assert (check);
  }
}

void Print_arr (const int* arr, int number)
{
  assert (arr);

  for (int i = 0; i < number; i++)
    printf("%d ", *(arr + i));
}

int Find_root (int i, int* in_order, int* pre_order, int number)
{
  assert (in_order);
  assert (pre_order);

  for (int j = 0; j < number; j++)
  {
    if (pre_order[i] == in_order[j])
      return j;
  }
  return -1;
}



int Return_tree (int* in_order, int* pre_order, int pre_index, int in_index, struct BTree_t* node, int in_predok, int number)
{
  int pre_left = -1;
  int pre_right = -1;
  int in_left = -1;
  int in_right = -1;
  int next = pre_index + 1;
  int tmp = in_order[in_index];
  in_order[in_predok] = -1;

  if (next >= number)
  {
    node[pre_order[pre_index]].left = -1;
    node[pre_order[pre_index]].right = -1;
    return number;
  }


  for (int i = in_index - 1; i >= 0; i--)
  {
    if (-1 == in_order[i])
      break; //дед съел тебя

    if (pre_order[next] == in_order [i])
    {
      in_left = i;
      pre_left = next;
      next = Return_tree (in_order, pre_order, pre_left, i, node, in_index, number);
      break;
    }
  }
  if (pre_left != -1)
    node[pre_order[pre_index]].left = pre_order[pre_left];
  else
    node[pre_order[pre_index]].left = -1;

  if (next >= number)
  {
    node[pre_order[pre_index]].right = -1;
    return number;
  }


  for (int i = in_index + 1; i < number; i++)
  {
    if (-1 == in_order[i])
      break;

    if (pre_order[next] == in_order [i])
    {
      in_right = i;
      pre_right = next;
      next = Return_tree (in_order, pre_order, pre_right, i, node, in_index, number);

      break;
    }
  }
  if (pre_right != -1)
    node[pre_order[pre_index]].right = pre_order[pre_right];
  else
    node[pre_order[pre_index]].right = -1;


  in_order[in_index] = tmp;
  return next;

}

void Print_Res (const struct BTree_t* node, int index, int number)
{
  assert (node);

  if (node[index].left != -1)
  {
    printf("%d ", 1);
    Print_Res (node, node[index].left, number);
  }
  else
  {
    if (global < number)
      printf("%d ", 0);
    global++;
  }
  if (node[index].right != -1)
  {
    printf("%d ", 1);
    Print_Res (node, node[index].right, number);
  }
  else
  {
    if (global < number)
      printf("%d ", 0);
    global++;
  }

  return;




}

// void Return_tree (int* in_order, int* pre_order, int index_pre, int number)
// {
//   if (Find_left (in_order, pre_order + 1, index_pre, number) >= 0)
//     Return_tree (in_order, pre_order, index_pre + 1, number);
//
//   if (Find_right (in_order, pre_order + 1, index_pre, number) >= 0)
//     Return_tree (in_order, pre_order, index_pre + 1, number);
//
//   printf ("%d ", index_pre);
//
//   return;
// }

// int Find_left (int* in_order, int* pre_order, int index_pre, int number)
// {
//   assert (in_order);
//   assert (pre_order);
//   int j = 0;
//
//   j = Find_root (index_pre - 1, in_order, pre_order, number);
//
//   for (int index_in = j ; index_in >= 0; index_in--)
//   {
//     if (pre_order[index_pre] == in_order[index_in])
//       return index_in;
//   }
//   return -1;
// }

// int Find_right (int* in_order, int* pre_order, int index_pre, int number)
// {
//   assert (in_order);
//   assert (pre_order);
//   int j = 0;
//
//   j = Find_root (index_pre - 1, in_order, pre_order, number);
//
//
//   for (int index_in = j; index_in < number; index_in++)
//   {
//     if (pre_order[index_pre] == in_order[index_in])
//       return index_in;
//   }
//   return -1;
// }

// int Return_tree (int* in_order, int* pre_order, int i, int j, int prev, struct BTree_t* tree, int number)
// {
//   int next = 0;
//   int left_child_in = 0;
//   int right_child_in = 0;
//   int right_child_pre = 0;
//   int counter = 0;
//   assert (in_order);
//   assert (pre_order);
//
//
//   left_child_in = -1;
//   right_child_pre = -1;
//   right_child_in = -1;
//   next = i;
//
//   for (counter = j; counter >= 0; counter--)
//   {
//     if (in_order[prev] == in_order[counter])
//       break;
//     if (pre_order[i + 1] == in_order[counter])
//     {
//       left_child_in = counter;
//       next = Return_tree (in_order, pre_order, i + 1, left_child_in, j, tree, number);
//       break;
//     }
//   }
//   if (left_child_in != -1)
//     tree[pre_order[i]].left = in_order[left_child_in];
//   else
//     tree[pre_order[i]].left = -1;
//
//   if (right_child_pre == -1)
//     right_child_pre = i + 1;
//   else
//     right_child_pre = next + 1;
//
//   for (counter = j; counter < number; counter++)
//   {
//     if (in_order[prev] == in_order[counter])
//       break;
//     if (pre_order[right_child_pre] == in_order[counter])
//     {
//       right_child_in = counter;
//       next = Return_tree (in_order, pre_order, right_child_pre, right_child_in, j, tree, number);
//       break;
//     }
//   }
//   if (right_child_in != -1)
//     tree[pre_order[i]].right = in_order[right_child_in];
//   else
//     tree[pre_order[i]].right = -1;
//   return next;
// }
