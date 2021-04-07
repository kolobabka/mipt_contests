#include <stdio.h>

int main ()
{

}

int compare (const void* x1, const void* x2)
{
  return *((int*)x1) - *((int*)x2);
}

int ncollisions(char **strs, int n, get_hash_t f)
{
  int* arr;
  int res = 0;

  arr = (int*) calloc (n, sizeof (int));

  for (int i = 0; i < n; i++)
  {
    arr[i] = f (strs[i]);
  }

  qsort (arr, n, sizeof(int), compare);
  
  for (int i = 0; i < n-1; i++)
  {
    if (arr[i] == arr[i+1])
      res++;
  }

  free (arr);
  return res;
}
