#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
  int n = 5;
  int j = 1, k = 2, sum = 0;
  printf("%d", sum);
  for (int i = 3; i <= n; i+2 )
  {
    for (j; j <= pow(i,2); j += k )
    {
      sum += j;
    }
    k += 2;
  }
  printf("%d", sum);
}
