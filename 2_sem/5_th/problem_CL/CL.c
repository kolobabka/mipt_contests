#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {
  struct node_t *next;
  int data;
};

// comparator for ints: lhs < rhs
int cmpless (const void* lhs, const void* rhs)
{
  int ilhs = *(const int *) lhs;
  int irhs = *(const int *) rhs;
  return ilhs - irhs;
}

int printarr (const int *coins, int ncoins)
{
  int idx;
  for (idx = 0; idx < ncoins; ++idx)
    printf("%d ", coins[idx]);
    printf("\n");
}

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

void insert_n_coins (struct node_t *head, int* coins, int ncoins)
{
  int n_coin = 0, i = 0;
  int cycle_len;
  struct node_t * cur;
  cycle_len = coins[ncoins - 1] - coins[0] + 1;
  cur = head;
  for (i = 0; i <= cycle_len; ++i)
    if (coins[n_coin] - 1 == i)
    {
      cur->data = head->data + 1;
      n_coin++;
    }
    cur = cur->next;
}
// 0 0 0 0
// 1 0 1 1 <--- inital
// 1 2 1 1 <--- real initial
// 2 1 1 2
// 1 1 2 2
int find_mc (int sum, int ncoins, int* coins, struct node_t* head)
{
  int cur_num; // 0 ---> sum
  int cycle_len;
  cycle_len = coins[ncoins - 1] - coins[0] + 1;
  for (cur_num = 0; cur_num < sum; cur_num++)
  {
    if (cur_num == 0)
    {
      print_cycle (head, cycle_len);
      insert_n_coins (head, coins, ncoins);
      print_cycle (head, cycle_len);
    }
  }
  return head->data;
}

int main ()
{
  int sum, ncoins, res, idx, mc = -1, cycle_len;
  int *coins;
  struct node_t *cycle = NULL;

  res = scanf("%d%d", &sum, &ncoins);
  assert (res == 2 && "we require two inputs");

  coins = calloc (ncoins, sizeof (int));
  assert (coins != NULL && "memory exhausted");

  for (idx = 0; idx < ncoins; ++idx)
  {
    res = scanf ("%d", coins + idx);
    assert (res == 1);
  }

  qsort (coins, ncoins, sizeof (int), cmpless);

  // for a while

  // 1. Create cyclic list
  cycle_len = coins[ncoins - 1] - coins[0] + 1;
  cycle = create_cycle (cycle_len);
  print_cycle (cycle, cycle_len);

  // 2. Move cyclic list
  //mc = find_mc (sum, ncoins, coins, cycle);
  // 3. Delete cyclic list
  free_cycle (cycle, cycle_len);

  free (coins);

  printf("%d\n", mc);

}
