#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
int Fill_lsms (int* lsms, int* arr, int len);
void Fill_Arr (int* arr, int n);
void Print_Arr (int* arr, int n);
//..............................................................................
//..............................................................................
int main ()
{
  int* arr = NULL;
  int* lsms = NULL;
  int len = 0, max = 0;
  int check = 0;

  check = scanf ("%d", &len);
  assert (check == 1);

  arr = (int*) calloc (len, sizeof (int));
  assert (arr);

  lsms = (int*) calloc (len, sizeof (int));
  assert (lsms);

  Fill_Arr (arr, len);
  max = Fill_lsms (lsms, arr, len);

  // Print_Arr (arr, len);
  // Print_Arr (lsms, len);

  printf("%d\n", max);

  free (arr);
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
int Fill_lsms (int* lsms, int* arr, int len)
{
  assert (lsms);
  assert (arr);
  int max = 0;

  lsms[0] = 1;
  max = lsms[0];

  for (int i = 1; i < len; i++)
  {
    lsms[i] = 1;
    for (int j = i - 1; j >= 0; j--)
    {
      if (lsms[j] + 1 > lsms[i] && (arr[i] % arr[j]) == 0)
        lsms[i] = lsms[j] + 1;
    }
    if (max < lsms[i])
      max = lsms[i];
  }

  return max;
}
//..............................................................................
//..............................................................................
