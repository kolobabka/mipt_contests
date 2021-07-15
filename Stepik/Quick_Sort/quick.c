#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
void Quick_Sort (int* arr, int left, int right);
int Partition (int* arr, int left, int right);
void Print_Arr (int* arr, int n);
void Fill_Arr (int* arr, int n);
//..............................................................................
//..............................................................................
int main ()
{
  int* arr = NULL;
  int n = 0;

  scanf("%d", &n);

  arr = (int*) calloc (n, sizeof (int));
  assert (arr);

  Fill_Arr (arr, n);

  Quick_Sort (arr, 0, n - 1);

  Print_Arr (arr, n);

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
