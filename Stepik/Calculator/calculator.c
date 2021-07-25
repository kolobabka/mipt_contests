#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
typedef struct elem {

  int num;
  int amount;
  struct elem* prev;

} Elem;
//..............................................................................
//..............................................................................
void Fill_Arr (int* arr, int num);
void Dynamic (int num);
//..............................................................................
//..............................................................................
int main ()
{
  int num = 0, res = 0;
  int check = 0;

  check = scanf("%d", &num);
  assert (check);

  Dynamic (num);
  return 0;
}
//..............................................................................
//..............................................................................
void Fill_Arr (int* arr, int num)
{
  assert (arr);
  int check = 0;

  for (int i = 0; i < num; i++)
  {
    check = scanf("%d", arr + i);
    assert (check == 1);
  }
}
//..............................................................................
//..............................................................................
void Dynamic (int num)
{
  Elem** arr = NULL;
  Elem* cur = NULL;
  Elem* tmp = NULL;
  int res = 0;

  if (num == 1)
  {
    printf("%d\n", 0);
    printf("%d\n", num);
    return;
  }

  arr = (Elem**) calloc (num + 1, sizeof (Elem*));
  assert (arr);

  for (int i = 0; i <= num; i++)
  {
    arr[i] = (Elem*) calloc (1, sizeof (Elem));
    assert (arr[i]);
  }

  arr[0]->amount = 0;
  arr[0]->num = 1;

  for (int i = 1; i < num; i++)
  {
    if ( ((i + 1) % 2 == 1)  && ((i + 1) % 3 != 0))
    {
      arr[i]->amount = arr[i - 1]->amount + 1;
      arr[i]->num = i + 1;
      arr[i]->prev = arr[i - 1];
      continue;
    }
    if (((i + 1) % 2 == 1) )
    {
      if (arr[i - 1]->amount < arr[((i + 1) / 3) - 1]->amount)
      {
        arr[i]->amount = arr[i - 1]->amount + 1;
        arr[i]->prev = arr[i - 1];
      }
      else
      {
        arr[i]->amount = arr[((i + 1) / 3) - 1]->amount + 1;
        arr[i]->prev = arr[((i + 1) / 3) - 1];
      }
      arr[i]->num = i + 1;
      continue;
    }
    if (((i + 1) % 3 != 0) )
    {
      if (arr[i - 1]->amount < arr[((i + 1) / 2) - 1]->amount)
      {
        arr[i]->amount = arr[i - 1]->amount + 1;
        arr[i]->prev = arr[i - 1];
      }
      else
      {
        arr[i]->amount = arr[((i + 1) / 2) - 1]->amount + 1;
        arr[i]->prev = arr[((i + 1) / 2) - 1];
      }
      arr[i]->num = i + 1;
      continue;
    }
    else
    {

      if (arr[i - 1]->amount <= arr[((i + 1) / 2) - 1]->amount && arr[i - 1]->amount <= arr[((i + 1) / 3) - 1]->amount)
      {
        arr[i]->amount = arr[i - 1]->amount + 1;
        arr[i]->prev = arr[i - 1];
        arr[i]->num = i + 1;
        continue;
      }
      if (arr[i - 1]->amount >= arr[((i + 1) / 2) - 1]->amount && arr[((i + 1) / 2) - 1]->amount <= arr[((i + 1) / 3) - 1]->amount)
      {
        arr[i]->amount = arr[((i + 1) / 2) - 1]->amount + 1;
        arr[i]->prev = arr[((i + 1) / 2) - 1];
        arr[i]->num = i + 1;
        continue;
      }
      if (arr[((i + 1) / 3) - 1]->amount <= arr[((i + 1) / 2) - 1]->amount && arr[i - 1]->amount >= arr[((i + 1) / 3) - 1]->amount)
      {
        arr[i]->amount = arr[((i + 1) / 3) - 1]->amount + 1;
        arr[i]->prev = arr[((i + 1) / 3) - 1];
        arr[i]->num = i + 1;
        continue;
      }

    }
  }

  res = arr[num - 1]->amount;
  cur = arr[num - 1];
  printf("%d\n", res);

  for (int i = 1; i <= res; i++)
  {
    tmp = arr[num + 1 - i];
    arr[num + 1 - i] = cur;
    arr[cur->num - 1] = tmp;
    cur = cur->prev;
  }

  printf("%d ", 1);
  for (int i = res; i >= 1; i--)
    printf("%d ", arr[num + 1 - i]->num);

  printf("\n");


  for (int i = 0; i <= num; i++)
    free (arr[i]);

  free (arr);
}
//..............................................................................
//..............................................................................
