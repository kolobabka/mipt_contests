#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//..............................................................................
//..............................................................................
void Search (int* arr, int* req, int num_elem, int num_req);
void Bin_Search (int* arr, int num_elem, int num);
void Fill_Arr (int* arr, int num_elem);
//..............................................................................
//..............................................................................
int main ()
{
  int check = 0;
  int* arr = NULL;
  int* req = NULL;
  int num_elem = 0, num_req = 0;

  check = scanf("%d", &num_elem);
  assert (check == 1);

  arr = (int*) calloc (num_elem, sizeof (int));
  assert (arr);

  Fill_Arr (arr, num_elem);

  check = scanf("%d", &num_req);
  assert (check == 1);

  req = (int*) calloc (num_req, sizeof (int));

  Fill_Arr (req, num_req);

  Search (arr, req, num_elem, num_req);

  free (req);
  free (arr);
}
//..............................................................................
//..............................................................................
void Fill_Arr (int* arr, int num_elem)
{
  assert (arr);

  int check = 0;

  for (int i = 0; i < num_elem; i++)
  {
    check = scanf("%d", arr + i);
    assert (check == 1);
  }
}
//..............................................................................
//..............................................................................
void Search (int* arr, int* req, int num_elem, int num_req)
{
  assert (arr);
  assert (req);

  for (int i = 0; i < num_req; i++)
    Bin_Search (arr, num_elem, req[i]);

  printf("\n");
}
//..............................................................................
//..............................................................................
void Bin_Search (int* arr, int num_elem, int num)
{
  assert (arr);
  int left = 0;
  int right = num_elem;
  int middle = 0;

  middle = (left + right) / 2;

  while (middle != left)
  {
    if (arr[middle] == num)
    {
      printf("%d ", middle + 1);
      return;
    }
    if (arr[middle] > num)
      right = middle;
    else
      left = middle;

    middle = (left + right) / 2;
  }
  if (arr[middle] == num)
  {
    printf("%d ", middle + 1);
    return;
  }

  printf("%d ", -1);
}
//..............................................................................
//..............................................................................
