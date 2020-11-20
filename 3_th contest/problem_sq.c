#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned partition(int *arr, unsigned low, unsigned high);
void qsort_impl(int *arr, unsigned low, unsigned high);
void qsorter(int *arr, unsigned len);


void fill_arr (int* arr, int len)
{
  for (int i = 0; i < len; i++)
  scanf ("%d", &arr[i]);
}


int main ()

{
  int *arr = NULL;
  unsigned len = 0, res = 0, low = 0, high = len - 1, count = 0;

  scanf ("%u", &len);

  arr = (int*) calloc (len, sizeof(int));

  fill_arr (arr, len);

  high = len - 1;


qsorter (arr, len);

for (int i = 0; i < len; i++)
{
  printf ("%d ", arr[i]);
}
printf ("\n");

printf("%d\n",res );



}

void qsort_impl(int *arr, unsigned low, unsigned high)
{
  if (low >= high)
    return;
  unsigned pi = partition(arr, low, high);
  if (pi > low)
    qsort_impl(arr, low, pi - 1);
  qsort_impl(arr, pi + 1, high);
}

void qsorter(int *arr, unsigned len)
{
  qsort_impl(arr, 0u, len - 1);
}

unsigned partition(int *arr, unsigned low, unsigned high)
{
  int tmp = 0, count_low = low, count_high = 1, less = 0;
  unsigned pos = 0;

  for (int i = low + 1; i <= high; i++)
  {
    if (arr[i] < arr[low])
      less++;
      printf ("less = %d\n",less);
  }
  pos = less + low;
  tmp = arr[pos];
  arr[pos] = arr[low];
  arr[low] = tmp;

  while (count_low < pos && pos < high)
  {
    if (arr[count_low] >= arr[pos])
    {
      tmp = arr[count_low];
      arr[count_low] = arr[pos + count_high];
      arr[pos + count_high] = tmp;
      count_high++;
    }
    else
      count_low++;
  }

  return pos;
}
