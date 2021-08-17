#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
//..............................................................................
//..............................................................................
typedef struct list_node {

  struct list_node* next;
  struct list_node* prev;

  int data;
} List;
//..............................................................................
//..............................................................................
typedef struct Hash_cell {

    struct Hash_cell* next;
    struct Hash_cell* prev;
    struct list_node* item;

} Hash_cell;
//..............................................................................
//..............................................................................
List* Delete_From_Table (Hash_cell** table, List** start, List** end, int request);
void Table_Destructor (Hash_cell** table, int len_table);
List* Search_List (Hash_cell** table, int request);
void Add_Hash_Table (Hash_cell** table, List* cur);
int Cache (int size, int num, Hash_cell** table);
List* Move_To_Start (List** start, List** cur);
void List_Destructor (List* start);
void Print_List (List* start);
int Hash_of_Data (int data);
//..............................................................................
//..............................................................................
int main () {

  Hash_cell** table = NULL;

  int len_table = 2137;
  int size = 0;
  int num = 0;
  int result = 0;

  assert (scanf ("%d%d", &size, &num) == 2);

  table = (Hash_cell**) calloc (len_table, sizeof (Hash_cell*));
  assert (table);

  for (int i = 0; i < len_table; i++) {

    table[i] = (Hash_cell*) calloc (1, sizeof (Hash_cell));
    assert (table[i]);
  }

  result = Cache (size, num, table);

  Table_Destructor (table, len_table);

  printf("%d\n", result);
}
//..............................................................................
//..............................................................................
int Cache (int size, int num, Hash_cell** table) {

  List* start = NULL;
  List* end = NULL;
  List* cur = NULL;
  int cache_hit = 0;
  int list_size = 0;
  int request = 0;
  int key = 0;

  assert (table);

  assert (scanf ("%d", &request) == 1);

  start = (List*) calloc (1, sizeof (List));
  assert (start);

  start->data = request;
  end = start;
  list_size++;

  // printf("i = 0, start->data = %d\n", start->data);
  key = Hash_of_Data (request);
  table[key]->item = start;

  for (int i = 1; i < num; i++) {

    assert (scanf ("%d", &request) == 1);

    cur = Search_List (table, request);

    if (cur)  {

      cache_hit++;
      end = Move_To_Start (&start, &cur);

    }
    else  {

      if (list_size < size) {

        cur = (List*) calloc (1, sizeof (List));
        assert (cur);

        cur->data = request;
        cur->next = start;
        start->prev = cur;
        start = cur;

        Add_Hash_Table (table, cur);
        list_size++;

      }
      else
        end = Delete_From_Table (table, &start, &end, request);
    }

    // printf ("request = %d\n", request);
    // Print_List (start);
    // printf ("end->data = %d\n", end->data);
    // printf ("cache = %d\n", cache_hit);
    //printf("i = %d, start->data = %d\n", i, start->data);
  }

  List_Destructor (start);

  return cache_hit;
}
//..............................................................................
//..............................................................................
List* Search_List (Hash_cell** table, int request) {

  Hash_cell* cur = NULL;
  int key = 0;
  assert (table);

  key = Hash_of_Data (request);
  cur = table[key];

  while (cur->next) {

    if (cur->item) {

      if (cur->item->data == request)
        return cur->item;
      else
        cur = cur->next;

    }
    else
      return NULL;
  }

  if (cur->item) {

    if (cur->item->data == request)
      return cur->item;
    else
      return NULL;
  }
  else
    return NULL;

  return NULL;
}
//..............................................................................
//..............................................................................
int Hash_of_Data (int data) {

    int key = 0;

    int size = 2137;
    int prime = 2909;
    int coeff_1 = 211;
    int coeff_2 = 521;

    key = ((coeff_1 * data + coeff_2) % prime) % size;

    return key;
}
//..............................................................................
//..............................................................................
List* Move_To_Start (List** start, List** cur)  {

  List* end = NULL;
  assert (*start);
  assert (*cur);

  end = *start;

  while (end->next)
    end = end->next;

  if (*cur == *start)
    return end;

  if (end == *cur)
    end = (*cur)->prev;

  (*cur)->prev->next = (*cur)->next;

  if ((*cur)->next)
    (*cur)->next->prev = (*cur)->prev;

  (*start)->prev = *cur;
  (*cur)->next = *start;
  (*cur)->prev = NULL;
  *start = *cur;

  return end;
}
//..............................................................................
//..............................................................................
void Add_Hash_Table (Hash_cell** table, List* cur) {

  Hash_cell* tmp = NULL;
  int key = 0;
  assert (table);
  assert (cur);

  key = Hash_of_Data (cur->data);
  tmp = table[key];

  if (tmp->item == NULL)  {

    tmp->item = cur;
    return;
  }

  while (tmp->next)
    tmp = tmp->next;

  tmp->next = (Hash_cell*) calloc (1, sizeof (Hash_cell));
  assert (tmp->next);

  tmp->next->item = cur;
  tmp->next->prev = tmp;
}
//..............................................................................
//..............................................................................
List* Delete_From_Table (Hash_cell** table, List** start, List** end, int request)
{
  Hash_cell* tmp = NULL;
  int key = 0;
  assert (table);
  assert (end);

  key = Hash_of_Data ((*end)->data);
  tmp = table[key];

  if (tmp->item->data == (*end)->data) {

    if (tmp->next == NULL)
      tmp->item = NULL; //ATTENTION!!!
    else  {

      table[key] = tmp->next;
      table[key]->prev = NULL;
      free (tmp);
    }
  }
  else {

    while (tmp->item->data != (*end)->data)
      tmp = tmp->next;

    if (tmp->prev)
      tmp->prev->next = tmp->next;
    if (tmp->next)
      tmp->next->prev = tmp->prev;

    free (tmp);
  }

  (*end)->data = request;

  (*end) = Move_To_Start (start, end);

  Add_Hash_Table (table, *start);

  return (*end);
}
//..............................................................................
//..............................................................................
void Print_List (List* start) {

  assert (start);

  while (start->next) {

    printf ("%d ", start->data);
    start = start->next;
  }

  printf("%d\n", start->data);
}
//..............................................................................
//..............................................................................
// void List_Destructor (List* start) {
//
//   assert (start);
//
//   while (start->next) {
//
//     start = start->next;
//     free (start->prev);
//   }
//
//   if (start->prev)
//     free (start->prev);
//
//   free (start);
// }
//..............................................................................
//..............................................................................
void Table_Destructor (Hash_cell** table, int len_table) {

  Hash_cell* tmp = NULL;
  assert (table);

  for (int i = 0; i < len_table; i++) {

    tmp = table[i];

    while (tmp->next) {

      tmp = tmp->next;
      free (tmp->prev);
    }

    if (tmp->prev)
      free (tmp->prev);

    free (tmp);
  }

  free (table);
}
void List_Destructor (List* top) {

  if (top == NULL)
  {
    return;
  }

  List_Destructor (top->next);
  free (top);
  return;
}
