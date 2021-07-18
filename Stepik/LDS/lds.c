#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
//..............................................................................
//..............................................................................
typedef struct elem {

  int data;
  int index;

} Elem;
//..............................................................................
//..............................................................................
int Fill_lds (Elem* lds, int* arr, int len);
void Fill_Arr (int* arr, int n);
void Print_Arr (int* arr, int n);
//..............................................................................
//..............................................................................
int main ()
{
  int* arr = NULL;
  Elem* lds = NULL;
  int len = 0, max = 0;
  int check = 0;

  check = scanf ("%d", &len);
  assert (check == 1);

  arr = (int*) calloc (len, sizeof (int));
  assert (arr);

  lds = (Elem*) calloc (len + 2, sizeof (Elem));
  assert (lds);

  Fill_Arr (arr, len);
  max = Fill_lds (lds, arr, len);

  // Print_Arr (arr, len);
  // Print_Arr (lds, len);

  // printf("%d\n", max);

  free (arr);
  free (lds);
}
//..............................................................................
//..............................................................................
void Fill_Arr (int* arr, int n)
{
  assert (arr);
  int check = 0;

  for (int i = 0; i < n; i++)
  {
    check = scanf ("%d", arr + i);
    assert (check == 1);
  }
}
//..............................................................................
//..............................................................................
void Print_Arr (int* arr, int n)
{
  assert (arr);

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");
}
//..............................................................................
//..............................................................................
int Fill_lds (Elem* lds, int* arr, int len)
{
  assert (lds);
  assert (arr);
  int max = 0, index = 0, last = 1;
  int left = 0, right = 0, middle = 0;
  int* tmp = NULL;

  int max_right = 0;

  lds[0].data = INT_MAX;
  lds[0].index = INT_MAX;
  for (int i = 1; i < len + 2; i++)
  {
    lds[i].data = INT_MIN;
    lds[i].index = INT_MAX;
  }


  for (int i = 0; i < len; i++)
  {
    left = 0;
    right = len + 1;

    while (left + 1 < right)
    {
      middle = (left + right) / 2;
      if (lds[middle].data >= arr[i])
        left = middle;
      else
        right = middle;
    }
    if (lds[right].data == INT_MIN || lds[right + 1].data == INT_MIN)
    {
      lds[right].data = arr[i];
      lds[right].index = i;
    }
    else
    {
      if (lds[right].index > i)
      {
        lds[right].data = arr[i];
        lds[right].index = i;
      }
    }
    // if (lds[right + 1].data == INT_MIN || lds[right].data == INT_MIN)
    // {
    //   lds[right].data = arr[i];
    //   lds[right].index = i;
    // }
    // else
    // {
    //   if (lds[right - 1].data != INT_MAX && lds[right - 1].data > arr[i])
    //   {
    //     lds[right].data = arr[i];
    //     lds[right].index = i;
    //   }
    // }
  }


  for (int i = 0; i < len + 2; i++)
    printf("%d ", lds[i].data);

  printf("\n");

  for (int i = 1; i < len + 1; i++)
  {
    if (lds[i].data == INT_MIN)
    {
      last = lds[i - 1].data;
      break;
    }
    max++;
  }

  for (int i = len - 1; i >= 0; i--)
  {
    if (arr[i] == last)
    {
      index = i;
      break;
    }
  }

  printf("index = %d\n", max);

  // tmp = (int*) calloc (max + 1, sizeof (int));
  // assert (tmp);
  //
  // tmp[0] = index + 1;
  //
  // for (int i = index; i >= 0; i--)
  // {
  //   if ( (lds[i] == lds[index] - 1) && arr[i] >= arr[index])
  //   {
  //     tmp[last] = i + 1;
  //     index = i;
  //     last++;
  //   }
  // }
  //
  // for (int i = max - 1; i >= 0; i--)
  //   printf("%d ", tmp[i]);
  //
  // printf("\n");
  // free (tmp);

}
//..............................................................................
//..............................................................................
