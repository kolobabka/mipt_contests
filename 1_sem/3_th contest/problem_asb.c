#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int arrpopcount(unsigned char *parr, int len);

int main ()
{
  unsigned char parr[] = {0, 0, 0, 0, 0} ;
  int len = 5, res = 0;

  res = arrpopcount (parr, len);

  printf ("%d\n", res);
}

int arrpopcount(unsigned char *parr, int len)
{
  int count = 0, j = 0, check = 0;

  for (int i = 0; i < len; i++)
  {
    for (j; j < 32; j++)
    {
      check = (parr[i] >> j) & 1u;
      printf ("check{%d} = %d\n", j, check);
      if ( check == 1)
      {
        count++;
        check = 0;
      }
    }
    printf ("count = %d\n", count);
    j = 0;
  }
  return count;
}
