#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
void Print_Arr (int* arr, int len);
void Fill_Arr (int* arr, int len);
void merge_sort_imp (int *arr, int l, int r);
void merge_sort (int* arr, int n);
void merge (int *arr, int l, int m, int r);
//..............................................................................
int main ()
{
  int* arr = NULL;
  int len = 10;

  arr = (int*) calloc (len, sizeof (int));

  Fill_Arr (arr, len);
  Print_Arr (arr, len);

  free (arr);
}
//..............................................................................
void merge_sort_imp (int *arr, int l, int r)
{
  int m = 0;
  if (l >= r)
    return;
  m = (l + r) / 2;
  merge_sort_imp (arr, l, m);
  merge_sort_imp (arr, m + 1, r);
  merge (arr, l, m, r);
}
//..............................................................................
void merge_sort (int* arr, int n)
{
  merge_sort_imp (arr, 0, n - 1);
}
//..............................................................................
void merge (int *arr, int l, int m, int r)
{

}
//..............................................................................
void Fill_Arr (int* arr, int len)
{
  assert (arr);
  assert (len);

  for (int counter = 0; counter < len; counter++)
    arr[counter] = len - counter;
}
//..............................................................................
void Print_Arr (int* arr, int len)
{
  assert (arr);
  assert (len);

  for (int counter = 0; counter < len; counter++)
    printf("%d ", arr[counter]);
}
