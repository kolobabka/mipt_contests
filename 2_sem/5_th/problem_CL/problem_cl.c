#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
struct node_t {
  struct node_t *next;
  int data;
};
//..............................................................................
int cmpless (const void* lhs, const void* rhs);
void print_cycle (struct node_t* head, int nelts);
struct node_t *create_cycle (int size);
void free_cycle (struct node_t* head, int nelts);
int min_search (struct node_t* head, int* coins, int ncoins, int sum);
int insert_n_coins (struct node_t *head, int* coins, int ncoins, int sum);
//..............................................................................
int main ()
{
  int sum = 0, ncoins = 0;
  int res = 0, cycle_len = 0;
  int *coins = NULL;
  struct node_t *cycle = NULL;

  res = scanf("%d%d", &sum, &ncoins);
  assert (res == 2 && "we require two inputs");

  coins = calloc (ncoins, sizeof (int));
  assert (coins != NULL && "memory exhausted");

  for (int idx = 0; idx < ncoins; ++idx)
  {
    res = scanf ("%d", coins + idx);
    assert (res == 1);
  }

  qsort (coins, ncoins, sizeof (int), cmpless);

  cycle_len = coins[ncoins - 1] - coins[0] + 1;
  cycle = create_cycle (cycle_len);

  res = insert_n_coins (cycle, coins, ncoins, sum);

  //print_cycle (cycle, cycle_len);

  printf("%d\n", res);

  free_cycle (cycle, cycle_len);

  free (coins);

}
//..............................................................................
struct node_t *create_cycle (int size)
{
  int i;
  struct node_t * start = NULL;
  struct node_t * cur = NULL;

  assert (size > 0);

  start = (struct node_t *) calloc (1, sizeof (struct node_t));
  cur = start;
  for (i = 1; i < size; ++i)
  {
    cur->next = (struct node_t *) calloc (1, sizeof (struct node_t));
    cur = cur->next;
  }
  cur->next = start;

  return start;
}
//..............................................................................
void print_cycle (struct node_t* head, int nelts)
{
  int i = 0;
  struct node_t *orig = head;
  assert (head);

  for (i; i < nelts; ++i)
  {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");

  assert (head == orig);
}
//..............................................................................
void free_cycle (struct node_t* head, int nelts)
{
  int i = 0;
  struct node_t *orig = head;
  assert (head);

  for (i; i < nelts; ++i)
  {
    struct node_t *tmp = head->next;
    free (head);
    head = tmp;
  }
}
//..............................................................................
int insert_n_coins (struct node_t *head, int* coins, int ncoins, int sum)
{
  struct node_t * start = NULL;
  struct node_t * cur = NULL;
  int counter = 0;
  int i = 0;
  int res = 0;

  cur = head;
  head->data = 1;

  cur = cur->next;
  counter = coins[0] + 1;

  while (cur != head)
  {
    for (int i = 0; i < ncoins; i++)
    {
      if (counter == coins[i])
      cur->data = 1;
    }
    cur = cur->next;
    counter++;
  }

  //printf("cur->data = %d\n", cur->data);

  res = min_search (head, coins, ncoins, sum);

  return res;


}
//..............................................................................
int cmpless (const void* lhs, const void* rhs)
{
  int ilhs = *(const int *) lhs;
  int irhs = *(const int *) rhs;
  return ilhs - irhs;
}
//..............................................................................

int min_search (struct node_t* head, int* coins, int ncoins, int sum)
{
  struct node_t* cur = NULL;
  struct node_t** pointers = NULL;
  struct node_t* tmp = NULL;
  int min = 0;
  int res = 0;
  int counter = 0;
  int len = 0;
  int cur_m = 0;

  cur = head;
  len = coins[ncoins - 1] - coins[0] + 1;
  cur_m = coins[ncoins - 1];

  min = sum;
  pointers = (struct node_t**) calloc (ncoins, sizeof (struct node *));

  for (int i = 1; i <= len; i++)
  {
    if (i == len - (coins[ncoins - counter - 1] - coins[0]))
    {
      //printf("data = %d\n", cur->data);
      pointers[counter] = cur;
      counter++;
    }
    cur = cur->next;
  }
  cur = head;

  while (cur_m < sum)
  {
    for (int i = 0; i < ncoins; i++)
    {
      if ((pointers[i])->data < min && (pointers[i])->data != 0)
        min = (pointers[i])->data;
    }
    cur->data = min + 1;
    res = cur->data;
    cur = cur->next;
    tmp = pointers[0];
    for (int i = 0; i < ncoins; i++)
    {
      pointers[i] = pointers[i]->next;
    }
    cur_m++;
    min = sum;
  }
  free (pointers);
  return res;
}
