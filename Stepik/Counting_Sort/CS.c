#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
void Fill_Arr (int* arr, int n, int num[]);
void Counting_Sort (int* arr, int num[]);
void Print_Arr (int* arr, int n);
//..............................................................................
//..............................................................................
int main ()
{
  int* arr = NULL;
  int len = 0;
  int check = 0;
  int num[10] = {0};

  check = scanf ("%d", &len);
  assert (check == 1);

  arr = (int*) calloc (len, sizeof (int));
  assert (arr);

  Fill_Arr (arr, len, num);

  Counting_Sort (arr, num);

  Print_Arr (arr, len);

  free (arr);
}
//..............................................................................
//..............................................................................
void Fill_Arr (int* arr, int n, int num[])
{
  assert (arr);
  int check = 0;

  for (int i = 0; i < n; i++)
  {
    check = scanf ("%d", arr + i);
    assert (check == 1);
    num[arr[i] - 1]++;
  }
}
//..............................................................................
//..............................................................................
void Counting_Sort (int* arr, int num[])
{
  assert (arr);
  int pos = 0;

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < num[i]; j++)
    {
      arr[pos + j] = i + 1;
    }
    pos += num[i];
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
