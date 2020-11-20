#include <stdio.h>

int main ()
{
  int count = 63, i = 0;
  unsigned long long N = 0;

  scanf ("%llu", &N);

  if (N == 0)
  {
    printf("%d\n", -1);
    return 0;
  }
  for (count; count >= 0; count--)
  {
     i = (N >> count) & 1u;
     if (i == 1)
      break;
  }

  printf("%d\n", count);
}
