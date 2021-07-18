#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
//..............................................................................
//..............................................................................
void Fill_Arr (int* arr, int n);
//..............................................................................
//..............................................................................
int main ()
{
  int check = 0;
  int* arr = NULL;
  int n = 0;

  check = scanf("%d%d", &n);
  assert (check == 1);

  arr = (int*) calloc (n, sizeof (int));
  assert (arr);

  Fill_Arr (arr, n);

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
int Random_Select (int* arr, int left, int right, int pos)
{
  assert (arr);

  if (left >= right)
    return arr[left];

  int x = rand () % right;
  
}
