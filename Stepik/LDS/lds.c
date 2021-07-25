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
typedef struct foo {

  int data;
  int index;
  struct foo* prev;

} Foo;
//..............................................................................
//..............................................................................
int Fill_lds (Elem* lds, Foo* arr, int len);
void Fill_Arr (Foo* arr, int n);
void Print_Arr (Foo* arr, int n);
//..............................................................................
//..............................................................................
int main ()
{
  Foo* arr = NULL;
  Elem* lds = NULL;
  int len = 0, max = 0;
  int check = 0;

  check = scanf ("%d", &len);
  assert (check == 1);

  arr = (Foo*) calloc (len, sizeof (Foo));
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
void Fill_Arr (Foo* arr, int n)
{
  assert (arr);
  int check = 0;

  for (int i = 0; i < n; i++)
  {
    check = scanf ("%d", &(arr[i].data));
    assert (check == 1);
    arr[i].index = i;
  }
}
//..............................................................................
//..............................................................................
void Print_Arr (Foo* arr, int n)
{
  assert (arr);

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i].data);

  printf("\n");
}
//..............................................................................
//..............................................................................
int Fill_lds (Elem* lds, Foo* arr, int len)
{
  assert (lds);
  assert (arr);
  int max = 0, index = 0, last = 1;
  int left = 0, right = 0, middle = 0;
  Elem* tmp = NULL;
  Foo* imtired = NULL;

  int max_right = 0;

  tmp = (Elem*) calloc (len + 1, sizeof (Elem));
  assert (tmp);

  lds[0].data = INT_MAX;
  lds[0].index = 0;

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
      if (lds[middle].data >= arr[i].data)
        left = middle;
      else
        right = middle;
    }
    lds[right].data = arr[i].data;
    lds[right].index = i;
    tmp[i + 1].index = lds[right - 1].index;
    tmp[i + 1].data = lds[right].data;
    arr[i].prev = arr + lds[right - 1].index;
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

  //
  // for (int i = 0; i < len + 2; i++)
  //   printf("%d ", lds[i].index);
  //
  // printf("\n");
  //
  // for (int i = 0; i < len + 1; i++)
  //   printf("%d ", tmp[i].index);
  //   printf("\n");
  // for (int i = 0; i < len + 1; i++)
  //   printf("%d ", tmp[i].data);
  //     printf("\n");

  for (int i = 1; i < len + 1; i++)
  {
    if (lds[i].data == INT_MIN)
    {
      last = lds[i - 1].data;
      break;
    }
    max++;
  }

  for (int i = len; i >= 0; i--)
  {
    if (tmp[i].data == last)
    {
      index = i;
      break;
    }
  }

  int godplsno = 0;

  for (int i = len - 1; i >= 0; i--)
  {
    if (arr[i].data == last)
    {
      godplsno = i;
      break;
    }
  }

  int* bar = (int*) calloc (max, sizeof (int));
  assert (bar);

  bar[max - 1] = godplsno + 1;

  imtired = arr + tmp[index].index;

  for (int i = max - 2; i >= 0; i--)
  {
    bar[i] = imtired->index + 1;
    imtired = imtired->prev;
  }

  printf("%d\n", max);

  for (int i = 0; i < max; i++)
    printf("%d ", bar[i]);

  printf("\n");

  index = len;


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
  free (tmp);
  free (bar);

}
//..............................................................................
//..............................................................................
