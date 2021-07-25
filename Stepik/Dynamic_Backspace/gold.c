#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
typedef struct dynam {

  int w;
  int* things;

} Dyn;
//..............................................................................
//..............................................................................
int Compare (const void* ptr_1, const void* ptr_2);
int Dynamic (int* weights, int num, int space);
void Fill_Arr (int* arr, int n);
void Print_Arr (int* arr, int n);
//..............................................................................
//..............................................................................
int main ()
{
  int* weights = NULL;
  int check = 0;
  int space = 0;
  int num = 0;
  int res = 0;

  check = scanf("%d%d", &space, &num);
  assert (check == 2);

  weights = (int*) calloc (num, sizeof (int));
  assert (weights);

  Fill_Arr (weights, num);
  qsort (weights, num, sizeof (int), Compare);

  res = Dynamic (weights, num, space);

  printf("%d\n", res);

  free (weights);
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
int Compare (const void* ptr_1, const void* ptr_2)
{
  assert (ptr_1);
  assert (ptr_2);

  int* first = (int*) ptr_1;
  int* second = (int*) ptr_2;

  return *first - *second;
}
//..............................................................................
//..............................................................................
int Dynamic (int* weights, int num, int space)
{
  assert (weights);

  Dyn* arr = NULL;
  int max = 0;
  int* foo = NULL;

  arr = (Dyn*) calloc (space + 1, sizeof (Dyn));
  assert (arr);

  foo = (int*) calloc (num, sizeof (int));
  assert (foo);

  for (int i = 0; i <= space; i++)
  {
    arr[i].things = (int*) calloc (num, sizeof (int));
    assert (arr[i].things);
  }

  for (int i = 1; i <= space; i++)
  {

    for (int j = 0; j < num; j++)
    {
      if (i - weights[j] < 0)
        continue;
      else
      {
        // if (i == 3 && j == 0)
        // {
        //   printf(" arr[i - weights[j]].w + weights[j] = %d\n", arr[i - weights[j]].w + weights[j]);
        //   printf("(arr[i - weights[j]].w + weights[j] = %d\n", (arr[i - weights[j]].w + weights[j]));
        //   printf("arr[i].w = %d\n", arr[i].w);
        //   printf("arr[i - weights[j]].things[j] = %d\n", arr[i - weights[j]].things[j]);
        //   printf("foo[j] = %d\n", foo[j]);
        // }
        if (max <= arr[i - weights[j]].w + weights[j] && (arr[i - weights[j]].w + weights[j] > arr[i].w) && arr[i - weights[j]].things[j] == 0)
        {
          arr[i].w = arr[i - weights[j]].w + weights[j];
          //arr[i - weights[j]].things[j] = 1;
          for (int k = 0; k < num; k++)
            arr[i].things[k] = arr[i - weights[j]].things[k];

          arr[i].things[j] = 1;

          // printf("j = %d ***first[%d]\n", j, i);
        }
        if (max < arr[i].w)
        {
          max = arr[i].w;
          for (int k = 0; k < num; k++)
            foo[k] = arr[i].things[k];
          // printf("j = %d ***second[%d]\n", j, i);
        }
        if (arr[i].w == 0)
        {
          arr[i].w = max;
          for (int k = 0; k < num; k++)
            arr[i].things[k] = foo[k];
          // printf("j = %d ***third[%d]\n", j, i);
        }
      }
    }
    // printf("ARR = ");
    //   for (int k = 0; k < num; k++)
    //     printf("%d ", arr[i].things[k]);
    //   printf("\n");
    // printf("FOO = ");
    // for (int k = 0; k < num; k++)
    //   printf("%d ", foo[k]);
    // printf("\n");
    //   printf("max = %d\n", max);
  }

  // for (int i = 0; i <= space; i++)
  //   printf("%d ", arr[i].w);
  //
  // printf("\n");

  for (int i = 0; i <= space; i++)
    free (arr[i].things);

  max = arr[space].w;
  free (arr);
  free (foo);

  return max;
}
