#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
void Counter (int* arr_1, int* arr_2, int* arr, int n, int m);
void Fill_Points (int* arr_1, int* arr_2, int n);
void Quick_Sort (int* arr, int left, int right);
int Partition (int* arr, int left, int right);
int Compare (const void* arr_1, const void* arr_2);
void Print_Arr (int* arr, int n);
void Fill_Arr (int* arr, int n);
//..............................................................................
//..............................................................................
int main ()
{
  int check = 0;
  int* arr = NULL;
  int* arr_1 = NULL;
  int* arr_2 = NULL;
  int n = 0, m = 0;

  check = scanf("%d%d", &n, &m);
  assert (check == 2);

  arr_1 = (int*) calloc (n, sizeof (int));
  assert (arr_1);
  arr_2 = (int*) calloc (n, sizeof (int));
  assert (arr_2);

  arr = (int*) calloc (m, sizeof (int));
  assert (arr);

  Fill_Points (arr_1, arr_2, n);

  Fill_Arr (arr, m);

  qsort (arr_1, n, sizeof (int), Compare);
  qsort (arr_2, n, sizeof (int), Compare);
  // Quick_Sort (arr_1, 0, n - 1);
  // Quick_Sort (arr_2, 0, n - 1);

  Counter (arr_1, arr_2, arr, n, m);

  //Print_Arr (arr, n);

  free (arr);
}
//..............................................................................
//..............................................................................
void Quick_Sort (int* arr, int left, int right)
{
  assert (arr);
  int pivot = 0;

  if (left >= right)
    return;

  pivot = Partition (arr, left, right);

  Quick_Sort (arr, left, pivot - 1);
  Quick_Sort (arr, pivot + 1, right);
}
//..............................................................................
//..............................................................................
int Partition (int* arr, int left, int right)
{
  assert (arr);
  int i = 0, j = 0, tmp = 0;
  int elem = 0;

  i = left + 1;
  j = left;

  elem = arr[left];

  for (i; i <= right; i++)
  {
    if (arr[i] > elem)
      continue;
    else
    {
      j++;
      tmp = arr[j];
      arr[j] = arr[i];
      arr[i] = tmp;
    }
  }

  tmp = arr[j];
  arr[j] = arr[left];
  arr[left] = tmp;

  return j;
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
void Fill_Points (int* arr_1, int* arr_2, int n)
{
  assert (arr_1);
  assert (arr_2);
  int check = 0;

  for (int i = 0; i < n; i++)
  {
    check = scanf("%d%d", arr_1 + i, arr_2 + i);
    assert (check == 2);
  }
}
//..............................................................................
//..............................................................................
void Counter (int* arr_1, int* arr_2, int* arr, int n, int m)
{
  assert (arr_1);
  assert (arr_2);
  assert (arr);
  int counter = 0;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr_1[j] <= arr[i])
        counter++;
      if (arr_2[j] < arr[i])
        counter--;
      if (arr_1[j] > arr[i] && arr_2[j] >= arr[i])
      {
        breakvoid;
      }
    }
    printf("%d ", counter);
    counter = 0;
  }
  printf("\n");
}
//..............................................................................
//..............................................................................
int Compare (const void* arr_1, const void* arr_2)
{
  assert (arr_1);
  assert (arr_2);

  int* first = (int*) arr_1;
  int* second = (int*) arr_2;

  return *first - *second;
}
