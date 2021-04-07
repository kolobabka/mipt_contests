#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//..............................................................................
struct node_t {
  struct node_t *next;
  int data;
};
//..............................................................................
void delete_list(struct node_t *top);
int list_make (struct node_t** node, FILE* inp, int N);
struct node_t *read_list(FILE *inp);
void delete_list(struct node_t *top);
//..............................................................................
int main (int argc, char** argv)
{
  int check = 666;
  FILE* inp = NULL;

  struct node_t* odd = NULL;
  struct node_t* even = NULL;

  if (argc < 2)
  {
    printf("Usage: <%sfile-to-open\n", argv[0]);
    return -1;
  }

  inp = fopen (argv[1], "r");

  if (inp == NULL)
  {
    perror ("File open error:");
    return -2;
  }

  odd = read_list (inp);

  delete_list (odd);

  fclose (inp);

  //slomal_litso = (long long*) calloc (1, sizeof(long long));
  //*slomal_litso = 228228228228228;
  //printf("%p\n", slomal_litso);

  // if (odd == NULL)
  //   printf("EBA-BOBA\n");
  // else
  //   printf("%d\n", odd->data);
  // printf("%p\n", odd);
  // odd = odd->next;
  // if (odd == NULL)
  //   printf("EBA-BOBA\n");
  // else
  //   printf("%d\n", odd->data);
  // printf("%p\n", odd);
  // odd = odd->next;
  // if (odd == NULL)
  //   printf("EBA-BOBA\n");
  // else
  //   printf("%d\n", odd->data);
  // printf("%p\n", odd);
  // odd = odd->next;
  // if (odd == NULL)
  //   printf("EBA-BOBA\n");
  // else
  //   printf("%d\n", odd->data);
  // printf("%p\n", odd);
  // odd = odd->next;
  // if (odd == NULL)
  //   printf("EBA-BOBA\n");
  // else
  //   printf("%d\n", odd->data);
  // printf("%p\n", odd);
  // odd = odd->next;
  // if (odd == NULL)
  //   printf("EBA-BOBA\n");
  // else
  //   printf("%d\n", odd->data);
  // printf("%p\n", odd);
  // odd = odd->next;
  // if (odd == NULL)
  //   printf("EBA-BOBA\n");
  // else
  //   printf("%d\n", odd->data);
  // printf("%p\n", odd);
  // odd = odd->next;
  // if (odd == NULL)
  //   printf("EBA-BOBA\n");
  // else
  //   printf("%d\n", odd->data);
  // printf("%p\n", odd);
  // //odd = odd->next;

}
//..............................................................................
int list_make (struct node_t** node, FILE* inp, int N)
{
  int check = 0, flag = 0, num = 0;
  struct node_t* prev = NULL;
  for (; ; )
  {
    check = fscanf (inp, "%d", &num);
    if (check != 1)
    {
      if (prev != NULL)
      {
        free (prev->next);
        prev->next = NULL;
      }
      break;
    }
    if ((num % 2) == N)
    {
      (*node)->data = num;
      prev = *node;
      (*node)->next = (struct node_t*) calloc (1, sizeof(struct node_t));
      assert ((*node)->next != NULL);
      flag = 1;
      (*node) = (*node)->next;

    }
  }
  return flag;
}

struct node_t *read_list(FILE *inp)
{
  int num = 0, check = 0, flag = 0;
  struct node_t * odd = NULL;
  struct node_t * even = NULL;
  struct node_t * start = NULL;
  struct node_t * start_2 = NULL;
  struct node_t * res = NULL;

  odd = (struct node_t *) calloc (1, sizeof (struct node_t));
  assert (odd != NULL);
  even = (struct node_t *) calloc (1, sizeof (struct node_t));
  assert (even != NULL);

  start = odd;
  start_2 = even;

  flag = list_make (&odd, inp, 0);
  if (flag == 0)
    start = NULL;

  fseek (inp, 0, SEEK_SET);

  flag = list_make (&even, inp, 1);
  if (flag == 0)
    start_2 = NULL;

  if (start != NULL)
  {
    res = start;
    while (start->next != NULL)
      start = start->next;
    start->next = start_2;
  }

  if (start == NULL)
  {
    res = start_2;
  }
  return res;
}

void delete_list(struct node_t *top)
{
  if (top == NULL)
  {
    return;
  }

  delete_list (top->next);
  free (top);
  return;
}


// int List_Maker (struct list_t** start, FILE* f)
// {
//   int len_list = 0, check = 0;
//   struct list_t* tmp_point = NULL;
//   assert (start != NULL);
//   fscanf (f,"%d", &len_list);
//
//   for (int counter = 1; counter <= len_list; counter++)
//   {
//     check = fscanf (f, "%d", &((*start)->data));
//     assert (check == 1);
//     tmp_point = *start;
//     if (counter == len_list)
//       break;
//     (*start)->next = (struct list_t*) calloc (1, sizeof(struct list_t));
//     assert ((*start)->next != NULL);
//
//     *start = (*start)->next;
//     (*start)->prev = tmp_point;
//   }
//   (*start)->next = NULL;
//
//   return 0;
// }
