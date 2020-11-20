#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_arr (int* arr, int len);
void sort_selection (int* arr, int len, int pos);
void fill_arr (int* arr, int len);

int main ()
{
  int* arr = NULL;
  int len = 0, check = 0, pos = 0;

  check = scanf ("%d", &len);
  assert (check);

  arr = (int*) calloc (len, sizeof(len));

  fill_arr (arr, len);

  check = scanf ("%d", &pos);
  assert (check);

  sort_selection (arr, len, pos);
  print_arr (arr, len);

  free (arr);
}

void fill_arr (int* arr, int len)
{
  assert (arr);

  for (int i = 0; i < len; i++)
    scanf ("%d", &arr[i]);
}

void sort_selection (int* arr, int len, int pos)
{
  int min = 0, tmp = 0, k = pos;
  assert (arr);

  min = arr[pos];
  for (int i = pos; i < len; i++)
  {
    if (min > arr[i])
    {
      min = arr[i];
      k = i;

    }
  }
  tmp = arr[pos];
  arr[pos] = arr[k];
  arr[k] = tmp;
}

void print_arr (int* arr, int len)
{
  assert (arr);
  for (int i = 0; i < len; i++)
    printf ("%d ", arr[i]);
}
