#include <stdio.h>

unsigned long long fib (unsigned long long n);
int main()
{
  unsigned long long n1 = 10, n2 = 20;

  int a1 = 0, a2 = 0, count = 0;

  for(int i = 0; i < 64; i++)
  {
    a1 = (n1 >> i) & 1u;
    a2 = (n2 >> i) & 1u;

    if (a1 != a2)
    count += 1;
  }
  printf("%d\n", count);
}
