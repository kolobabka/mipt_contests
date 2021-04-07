#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//..............................................................................
struct node_t {
  struct node_t *next;
  int data;
};
//..............................................................................
int list_is_a_loop(struct node_t *top);
struct node_t * make_a_loop (struct node_t *list, int pos);
struct node_t * create_list (struct node_t *list, int N);
void print_list (struct node_t* list, int N);
//..............................................................................
int main ()
{
  struct node_t * list = NULL;
  int N = 10;
  int pos = 3;
  list = (struct node_t*) calloc (1, sizeof (struct node_t));

  list = create_list (list, N);

  list = make_a_loop (list, pos);

  printf("%d\n", list_is_a_loop (list));

  print_list (list, N);
}
//..............................................................................
int list_is_a_loop(struct node_t *top)
{
  struct node_t * first = NULL;
  struct node_t * second = NULL;


  if (top == NULL)
  return 0;

  first = top;
  second = top;

  while (first != NULL && second != NULL)
  {

    second = second->next;
    if (second == first)
      return 1;
    if (second != NULL)
      second = second->next;
    if (second == first)
      return 1;

    first = first->next;
  }
  return 0;

}

struct node_t * create_list (struct node_t *list, int N)
{
  struct node_t * start = NULL;
  assert (list);

  start = list;

  for (int i = 1; i <= N; i++)
  {
    list->next = (struct node_t*) calloc (1, sizeof (struct node_t));
    list->data = i;
    list = list->next;
  }

  return start;
}

struct node_t * make_a_loop (struct node_t *list, int pos)
{
  struct node_t * start = NULL;
  struct node_t * prev = NULL;
  assert (list);

  start = list;

  for (int i = 1; i <= pos-1; i++)
  {
    prev = list;
    list = list->next;
  }
  list->next = prev;

  return start;
}

void print_list (struct node_t* list, int N)
{
  struct node_t * start = NULL;
  assert (list);

  for (int i = 1; i <= N; i++)
  {
    printf("data = %d\n", list->data);
    list = list->next;
  }
}
