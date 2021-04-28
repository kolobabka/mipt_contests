#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

void generator (int C);
int is_prime (unsigned n);

int main ()
{
  int res = 0;
  int C = 0;

  res = scanf ("%d", &C);
  assert (res == 1);

  generator (C);
}

void generator (int C)
{
  int max_len = 0;
  int tmp = 0;
  int a = 0;
  int b = 0;
  int n = 0;

  for (int i = (1 - C); i < C; i++)
  {
    for (int j = 2; j < C; j++)
    {
      while ( is_prime ( (n * n + i * n + j)))
      {
        n++;
        tmp++;
      }

      if (tmp > max_len)
      {
        max_len = tmp;
        a = i;
        b = j;
      }

      tmp = 0;
      n = 0;
    }
  }

  printf ("%d %d %d\n", a, b, max_len);
} 

int is_prime (unsigned n)
{
  int last = 0;
  if ((n == 2) || (n == 3))
    return 1;
  if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0))
    return 0;
  last = (int) sqrt(n) + 1;
  for (int j = 5; j <= last; j += 6)
    if (((n % j) == 0) || ((n % (j + 2)) == 0))
      return 0;
  return 1;
}