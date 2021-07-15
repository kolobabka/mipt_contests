#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
//..............................................................................
//..............................................................................
struct list_node {

  struct list_node* next;
  struct list_node* prev;

  int data;
};
//..............................................................................
//..............................................................................
struct hash_cell
{
    struct hash_cell* next;
    struct hash_cell* prev;
    struct list_node* item;

};
//..............................................................................
//..............................................................................

//..............................................................................
//..............................................................................
int Hash_of_Data (int data, int size);
int Cache (int size, int num);
struct list_node* Search_List (struct list_node** cells, int request, int size);
struct list_node* Move_To_Start (struct list_node* start, struct list_node* cur);
//..............................................................................
//..............................................................................
int main ()
{
  struct list_node* start = NULL;
  struct list_node* tmp = NULL;

  int size = 0;
  int num = 0;
  int result = 0;

  assert (scanf ("%d%d", &size, &num));

  result = Cache (size, num);

  printf("%d\n", result);
  // tmp = start;
  //
  // for (int i = 0; i < 10; i++)
  // {
  //   tmp->data = i;
  //   tmp->next = (struct list_node*) calloc (1, sizeof (struct list_node));
  //
  //   tmp->next->prev = tmp;
  //   tmp = tmp->next;
  //
  // }
  // tmp = start;
  //
  // for (int i = 0; i < 10; i++)
  // {
  //   printf("%d ", tmp->data);
  //   tmp = tmp->next;
  // }
  // printf("\n");
  //
  // start = Move_To_Start (start, tmp->prev);
  //
  // tmp = start;
  //
  // for (int i = 0; i < 10; i++)
  // {
  //   printf("%d ", tmp->data);
  //   tmp = tmp->next;
  // }
  // printf("\n");
  //
  // while (tmp)
  // {
  //   printf("%d ", tmp->data);
  //   tmp = tmp->prev;
  // }
  //
  // tmp = Search_List (start, 5);
  //
  // printf("qwer = %d\n", tmp->data);


}

int Cache (int size, int num)
{
  int request = 0;
  int cache_hit = 0;
  int list_size = 1;
  int key = 0;

  struct list_node* cur = NULL;
  struct hash_cell* tmp_hash = NULL;
  struct list_node* start = NULL;
  struct list_node* end = NULL;
  struct list_node* tmp = NULL;
  struct hash_cell* cells = NULL;

  scanf ("%d", &request);

  cur = (struct list_node*) calloc (1, sizeof (struct list_node));
  cells = (struct hash_cell*) calloc (size, sizeof (struct hash_cell));

  key = Hash_of_Data (request, size);

  cells[key].item = cur;

  cur->data = request;
  start = cur;
  end = start;

  for (int i = 1; i < num; i++)
  {
    scanf ("%d", &request);

    cur = Search_List (cells, request, size);
    if (cur)
    {
      cache_hit++;
      if (cur != start && cur == end)
        end = cur->prev;

      start = Move_To_Start (start, cur);
    }
    else
    {
      if (list_size < size)
      {
        start->prev = (struct list_node*) calloc (1, sizeof (struct list_node));
        start->prev->next = start;
        start = start->prev;
        start->data = request;
        list_size++;
        key = Hash_of_Data (request);
        if (!cells[key].item)
          cells[key].item = (start);
        else
        {
          tmp_hash = (struct hash_cell*) calloc (1, sizeof (struct hash_cell));

          if (cells[key].next)
          {
            cells[key].next->prev = tmp_hash;
            tmp_hash->next = cells[key].next;
            cells[key].next = tmp_hash;
            tmp_hash->prev = cells[key];
          }
          else
          {
            cells[key].next = tmp_hash;
            tmp_hash = cells[key];
          }
        }





      }
      else
      {
        end->data = request;
        end = end->prev;

        start = Move_To_Start (start, end->next);
      }
    }

  }
  tmp = start;
  while (tmp->next)
  {
    tmp = tmp->next;
    free (tmp->prev);
  }
  free (tmp);
  return cache_hit;
}
//..............................................................................
//..............................................................................
struct list_node* Search_List (struct hash_cell* cells, int request, int size)
{
  int key = 0;
  struct hash_cell cell;

  key = Hash_of_Data (request);
  cell = cells[key];

  if (cell.item == NULL)
    return 0;

  while (cell.next)
  {
    if (cell.item->data == request)
      return cell.item;

    cell = cell.next;
  }

  if (cell.item->data == request)
    return cell.item;

  return NULL;
}
//..............................................................................
//..............................................................................
struct list_node* Move_To_Start (struct list_node* start, struct list_node* cur)
{
  struct list_node* tmp = NULL;

  if (cur == start)
    return cur;

  cur->prev->next = cur->next;

  if (cur->next)
  {
    cur->next->prev = cur->prev;
  }

  start->prev = cur;
  cur->next = start;
  cur->prev = NULL;

  return cur;
}

int Hash_of_Data (int data, int size)
{
    int key = 0;

    int prime   = 2909;
    int coeff_1 = 211;
    int coeff_2 = 521;

    key = ((coeff_1 * data + coeff_2) % prime) % size;

    return key;
}
