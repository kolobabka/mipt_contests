#include <stdio.h>

int main ()
{
  int res = 0;
  int check = 0;
  unsigned N = 0;

  check = scanf ("%u", &N);

  for (int i = 2; i * i <= N; i++)
  {
    if (N % i == 0)
    {
      res = 1;
      break;
    }  
  }

  if (res == 0)
    printf ("%d\n", 1);
  else 
    printf ("%d\n", 0);
  
  return 0;
}

