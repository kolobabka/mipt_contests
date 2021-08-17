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
typedef struct Hash_cell
{
    struct Hash_cell* next;
    struct Hash_cell* prev;
    struct list_node* item;

} hash_cell;
//..............................................................................
//..............................................................................

//..............................................................................
//..............................................................................
int Hash_of_Data (int data);
int Cache (int size, int num, hash_cell** table);
struct list_node* Search_List (hash_cell** table, int request, int size);
struct list_node* Move_To_Start (struct list_node* start, struct list_node* cur);
//..............................................................................
//..............................................................................
int main ()
{
  hash_cell** table = NULL;

  int len_table = 2137;
  int size = 0;
  int num = 0;
  int result = 0;

  assert (scanf ("%d%d", &size, &num) == 2);

  table = (hash_cell**) calloc (len_table, sizeof (hash_cell*));
  assert (table);

  for (int i = 0; i < len_table; i++)
  {
    table[i] = (hash_cell*) calloc (1, sizeof (hash_cell));
    assert (table[i]);
  }

  result = Cache (size, num, table);

  printf("%d\n", result);

}

int Cache (int size, int num, hash_cell** table)
{
  int request = 0;
  int cache_hit = 0;
  int list_size = 1;
  int key = 0;

  struct list_node* cur = NULL;
  struct list_node* start = NULL;
  struct list_node* end = NULL;
  struct list_node* tmp = NULL;
  hash_cell* tmp_hash = NULL;

  assert (scanf ("%d", &request) == 1);


  cur = (struct list_node*) calloc (1, sizeof (struct list_node));

  key = Hash_of_Data (request);

  table[key]->item = cur;

  cur->data = request;
  start = cur;
  end = start;

  for (int i = 1; i < num; i++)
  {
    scanf ("%d", &request);

    cur = Search_List (table, request, size);
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
        assert (start->prev);
        start->prev->next = start;
        start = start->prev;
        start->data = request;
        list_size++;
        key = Hash_of_Data (request);
        if (table[key]->item == NULL)
        {
          table[key]->item = start;
        }
        else
        {
          tmp_hash = (hash_cell*) calloc (1, sizeof (hash_cell));

          if (table[key]->next)
          {
            table[key]->next->prev = tmp_hash;
            tmp_hash->next = table[key]->next;
            table[key]->next = tmp_hash;
            tmp_hash->prev = table[key];
            table[key]->item = start;
          }
          else
          {
            table[key]->next = tmp_hash;
            tmp_hash->item = start;
            tmp_hash->prev = table[key];
          }
        }
      }
      else
      {
        key = Hash_of_Data (end->data);
        tmp_hash = table[key];
        printf("gay = table[%d]->item = %p\n", key, table[key]->item);

        while (tmp_hash->item != end)
          tmp_hash = tmp_hash->next;

        if (tmp_hash->prev)
        {
          tmp_hash->prev->next = tmp_hash->next;
          if (tmp_hash->next)
            tmp_hash->next->prev = tmp_hash->prev;
        }

        if (tmp_hash->next)
        {
          table[key] = tmp_hash->next;
          table[key]->prev = NULL;
        }

        free (tmp_hash->item);
        tmp_hash->item = NULL;

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
struct list_node* Search_List (hash_cell** table, int request, int size)
{
  int key = 0;
  hash_cell* cell;

  key = Hash_of_Data (request);
  cell = table[key];

  if (cell->item == NULL)
    return NULL;

  while (cell->next)
  {
    if (cell->item->data == request)
      return cell->item;

    cell = cell->next;
  }

  if (cell->item->data == request)
    return cell->item;

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

int Hash_of_Data (int data)
{
    int key = 0;

    int size = 2137;
    int prime = 2909;
    int coeff_1 = 211;
    int coeff_2 = 521;

    key = ((coeff_1 * data + coeff_2) % prime) % size;

    return key;
}
