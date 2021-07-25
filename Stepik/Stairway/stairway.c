#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
int Max (int first, int second);
void Fill_Arr (int* cost, int num);
int Stairway (int* arr, int num);
//..............................................................................
//..............................................................................
int main ()
{
  int num = 0, check = 0, res = 0;
  int* cost = NULL;

  check = scanf("%d", &num);
  assert (check == 1);

  cost = (int*) calloc (num, sizeof (int));
  assert (cost);

  Fill_Arr (cost, num);

  res = Stairway (cost, num);

  printf("%d\n", res);

  free (cost);
  return 0;
}
//..............................................................................
//..............................................................................
void Fill_Arr (int* cost, int num)
{
  assert (cost);
  int check = 0;

  for (int i = 0; i < num; i++)
  {
    check = scanf("%d", cost + i);
    assert (check == 1);
  }
}
//..............................................................................
//..............................................................................
int Stairway (int* arr, int num)
{
  assert (arr);

  int max = 0;
  int* stairs = NULL;

  if (num == 1)
    return arr[0];

  stairs = (int*) calloc (num + 1, sizeof (int));
  assert (stairs);

  stairs[1] = arr[0];

  for (int i = 2; i <= num - 1; i++)
    stairs[i] = Max (stairs[i - 2], stairs[i - 1]) + arr[i - 1];

  if (stairs[num - 1] > stairs[num - 2])
    stairs[num] = stairs[num - 1] + arr[num - 1];
  else
    stairs[num] = stairs[num - 2] + arr[num - 1];

  // for (int i = 0; i <= num; i++)
  //   printf("stairs[%d] = %d\n", i, stairs[i]);

  max = stairs[num];

  free (stairs);
  return max;
}
//..............................................................................
//..............................................................................
int Max (int first, int second)
{
  int max = 0;

  max = first;

  if (second > max)
    max = second;

  return max;
}
//..............................................................................
//..............................................................................
