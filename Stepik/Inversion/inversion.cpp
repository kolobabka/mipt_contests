#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
void Merge (int* arr, int left, int middle, int right);
void Merge_Sort (int* arr, int left, int right);
void Print_Arr (int* arr, int n);
void Fill_Arr (int* arr, int n);
//..............................................................................
//..............................................................................
unsigned long long glob = 0;
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

  Merge_Sort (arr, 0, n - 1);

  // Print_Arr (arr, n);

  printf("%llu\n", glob);

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
void Merge_Sort (int* arr, int left, int right)
{
  assert (arr);
  int middle = (left + right) / 2;

  if (left < middle)
  {
    Merge_Sort (arr, left, middle);
    Merge_Sort (arr, middle + 1, right);
  }

  Merge (arr, left, middle, right);
}
//..............................................................................
//..............................................................................
void Merge (int* arr, int left, int middle, int right)
{
  assert (arr);

  const int n_1 = middle - left + 1;
  const int n_2 = right - middle;

  int L[n_1] = {0};
  int R[n_2] = {0};

  for (int i = 0; i < n_1; i++)
    L[i] = arr[left + i];

  for (int i = 0; i < n_2; i++)
    R[i] = arr[middle + i + 1];

  // for (int i = 0; i < n_1; i++)
  // {
  //   for (int j = 0; j < n_2; j++)
  //     if (L[i] > R[j])
  //       glob++;
  // }
  //printf("glob = %d\n", glob);
  int i = 0;
  int j = 0;

  for (int k = left; k <= right; k++)
  {
    if (i >= n_1)
    {
      arr[k] = R[j];
      j++;
      continue;
    }
    if (j >= n_2)
    {
      arr[k] = L[i];
      i++;
      continue;
    }
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
      glob += n_1 - i;
    }
  }
  // Print (arr, 10);
  // printf("\t\t\tEND\n");
  return;
}
