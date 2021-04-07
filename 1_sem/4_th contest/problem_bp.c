#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//..............................................................................

int alg_resolve (int* arr, int* new, int N , int S);
void fill_arr (int* arr, int len);
int moveright(int* arr, int key, int last);
void inssort(int *arr, int len);
void fill_arr_1000 (int* arr, int len);

//..............................................................................

int main ()
{
  int S = 0, N = 0, check = 0, res = 0;
  int* arr = NULL;
  int* new = NULL;

  check = scanf ("%d %d", &S, &N);
  assert (check == 2);

  arr = (int*) calloc (N, sizeof (int));
  assert (arr != NULL);

  fill_arr (arr, N);
  inssort (arr, N);

  new = (int*) calloc (S, sizeof (int));
  assert (new != NULL);

  fill_arr_1000 (new, S);

  res = alg_resolve (arr, new, N, S);

  printf("%d\n", res);

}
//..............................................................................

void inssort(int *arr, int len)
{
  int i = 0;

  assert (arr != NULL);
  for (i; i < len; ++i)
  {
    int key = 0, pos = 0;
    key = arr[i];
    pos = moveright(arr, key, i);
    arr[pos] = key;
  }
}

//..............................................................................

int moveright(int* arr, int key, int last)
{
  int i = 0;

  for (i = last - 1; i >= 0; i--)
  {
    if (arr[i] <= key)
      break;

    arr[i + 1] = arr[i];

  }
  return i+1;
}

//..............................................................................

void fill_arr (int* arr, int len)
{
  int check = 0;
  for (int i = 0; i < len; i++)
  {
    check = scanf("%d", &arr[i]);
    assert (check == 1);
  }
}

//..............................................................................

int alg_resolve (int* arr, int* new, int N , int S)
{
  int res = 0;

  for (int i = 0; i < N; i++)
  {
    if (res + arr[i] <= S)
      res += arr[i];
    else
      return i;
  }
  return N;
}


void fill_arr_1000 (int* arr, int len)
{
  int check = 0;
  for (int i = 1; i < len; i++)
  {
    arr[i] = 10002;
  }
}
