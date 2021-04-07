#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//..............................................................................
struct node_t {
  struct node_t *next;
  int data;
};

struct node_t * reverse(struct node_t *top);
struct node_t * create_list (struct node_t *list, int N);
void print_list (struct node_t* list, int N);

int main ()
{
  struct node_t * list = NULL;
  int N = 3;
  int pos = 3;
  list = (struct node_t*) calloc (1, sizeof (struct node_t));

  list = create_list (list, N);

  //list = make_a_loop (list, pos);

  print_list (list, N);

  list = reverse (list);

  print_list (list, N);

}

void print_list (struct node_t* list, int N)
{
  struct node_t * start = NULL;
  assert (list);
  start = list;

  for (; ;)
  {
    printf("data = %d\n", start->data);
    if (start->next == NULL)
      break;
    start = start->next;
  }
  printf("Nu i kak??? ---> %d\n", start->data);

}

struct node_t * create_list (struct node_t *list, int N)
{
  struct node_t * start = NULL;
  assert (list);

  start = list;

  for (int i = 1; i <= N; i++)
  {
    list->data = i;
    if (i != N)
    {
      list->next = (struct node_t*) calloc (1, sizeof (struct node_t));
      list = list->next;
    }
  }

  return start;
}

struct node_t * reverse(struct node_t *top)
{
  struct node_t * tmp = NULL;
  struct node_t * cur = NULL;
  struct node_t * next = NULL;
  struct node_t * prev = NULL;
  struct node_t * start = NULL;


  if (NULL == top) return NULL;
  if (NULL == top->next) return top;


  while (top != NULL)
  {
    if (top->next == NULL)
    {
      top->next = prev;
      prev = top;
      break;
    }
    cur = top;
    next = cur->next;
    tmp = next->next;
    next->next = cur;
    top->next = prev;
    prev = next;
    top = tmp;
  }

  return prev;
}
