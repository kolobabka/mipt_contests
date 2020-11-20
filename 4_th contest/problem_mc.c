#include <stdio.h>

int moveright(int* arr, int key, int last);
void inssort(int *arr, int len);
int main ()
{
  int S = 10, N = 3, flag_min = 0, j = 0;
  int arr[3] = {3, 1, 4};

  int new[10] = {0};

  inssort (arr, N);

  for (int i = arr[j]; i < 10; i++)
  {
    if ()
    new[i-1] = arr[j]
  }
/* int min_element (int* arr, int N)
{
  int min = arr[0];
  for (int i = 1; i < N; i++)
  {
    if (arr[i] < arr[0])
      min =
  }
} */

void inssort(int *arr, int len)
{
  int i;
  for (i = 0; i < len; ++i)
  {
    int key = 0, pos = 0;
    key = arr[i];
    pos = moveright(arr, key, i);
    arr[pos] = key;
  }
}

int moveright(int* arr, int key, int last)
{
    int i = 0;

    for (i = last - 1; i >=0; i--)
    {
        if (arr[i] <= key)
            break;

        arr[i + 1] = arr[i];
    }

    return i+1;
}
