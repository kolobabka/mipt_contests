#include <stdio.h>
#include <stdlib.h>

void fill_arr (int* arr, int len);
int moveright(int *arr, int key, int last);
void inssort(int *arr, int len);
void print_arr (int* arr, int len);

int main()
{
  int* arr = NULL;
  int len = 0;
  scanf("%d", &len);

  arr = (int*) calloc (len, sizeof(int));
  fill_arr(arr, len);

  print_arr (arr, len);

  printf("\n");

  inssort(arr, len);

  print_arr (arr, len);
}

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

void fill_arr (int* arr, int len)
{
  for (int i = 0; i < len; i++)
  scanf ("%d", &arr[i]);
}

void print_arr (int* arr, int len)
{
  for (int i = 0; i < len; i++)
  printf ("%d", arr[i]);
}
