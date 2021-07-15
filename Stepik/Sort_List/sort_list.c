#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
typedef struct alphabet {

  int freq;
  struct alphabet* next;
  struct alphabet* prev;

} Alp;
//..............................................................................
//..............................................................................
Alp* Sort_List (Alp* node);
//..............................................................................
//..............................................................................
int main ()
{
  Alp* first = (Alp*) calloc (1, sizeof (Alp));
  Alp* start = first;
  first->freq = 0;

  printf("pointer[0] = %p\n", first);
  for (int i = 1; i < 2; i++)
  {
    Alp* tmp = (Alp*) calloc (1, sizeof (Alp));
    tmp->freq = i;
    first->next = tmp;
    tmp->prev = first;
    first = first->next;
    printf("pointer[%d] = %p\n", i, first);
    //printf("basta\n");
    // return 0;
  }

  first = start;

  start = Sort_List (start);

  first = start;


  // for (int i = 0; i < 10; i++)
  // {
  //   printf("freq--[%d] = %d\n", i, first->freq);
  //   first = first->next;
  // }

  // start = Sort_List (start);
  // Alp* restart = NULL;
  //
  // restart = start;
  // start = start->next;
  // first = start;
  //
  // while (start) // or it :)
  // {
  //   if (restart->freq > start->freq)
  //   {
  //     start->prev = restart->prev;
  //     restart->prev = start;
  //     start = start->next;
  //   }
  //   else
  //   {
  //     start->prev = restart;
  //     restart->next = start;
  //     restart->prev->next = restart;
  //     break;
  //   }
  // }
  // //restart->next = NULL;
  //
  // start = first;

  for (int i = 0; i < 2; i++)
  {
    printf("pointer[%d] = %d\n", i, first->freq );
    first = first->next;
  }



  while (start->next)
  {
    free (start->prev);
    start = start->next;
  }
  free (start->prev);
  free (start);
}
//..............................................................................
//..............................................................................
Alp* Sort_List (Alp* node)
{
  assert (node); //100% it falls :)
  Alp* start = NULL;
  Alp* restart = NULL;

  if (node->freq > node->next->freq)
    restart = node->next;
  else
  {
    restart = node;
    return node;
  }
  start = node;
  node = node->next;

  while (node) // or it :)
  {
    if (start->freq > node->freq)
    {
      node->prev = start->prev;
      start->prev = node;
      if (!node->next)
        break;
      node = node->next;
    }
    else
    {
      node->prev = start;
      start->next = node;
      start->prev->next = start;
      return restart;
    }
  }
  node->next = start;
  start->prev = node;
  start->next = NULL;
  return restart;
}
