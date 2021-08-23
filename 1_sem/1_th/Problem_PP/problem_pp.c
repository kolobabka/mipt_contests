#include <stdio.h>
#include <assert.h>
//..............................................................................
//..............................................................................
unsigned Result (unsigned long long num, unsigned mod, unsigned period);
unsigned Fib_Mod (unsigned counter, unsigned mod);
unsigned Piz (unsigned mod);
//..............................................................................
//..............................................................................
int main () {

  unsigned long long num = 0;
  unsigned mod = 0;
  unsigned res = 0;
  unsigned period = 0;

  assert ((scanf ("%llu%u", &num, &mod)) == 2);

  period = Piz (mod);

  res = Result (num, mod, period);

  printf("%u %u\n", res, period);
}
//..............................................................................
//..............................................................................
unsigned Piz (unsigned mod) {

  unsigned first = 1;
  unsigned second = 1;
  unsigned third = 1;

  unsigned period = 1;

  if (mod == 1)
    return 1;

  while (1) {

    third = (first + second) % mod;
    first = second;
    second = third;

    period++;

    if (first == 0 && second == 1)
      break;
  }

  return period;
}
//..............................................................................
//..............................................................................
unsigned Result (unsigned long long num, unsigned mod, unsigned period) {

  unsigned res = 0;
  unsigned counter = 0;

  counter = num % period;

  res = Fib_Mod (counter, mod);

  return res;
}
//..............................................................................
//..............................................................................
unsigned Fib_Mod (unsigned counter, unsigned mod) {

  unsigned first = 0;
  unsigned second = 1;
  unsigned third = 0;

  if (counter == 0)
    return 0;

  if (counter == 1)
    return 1;



  for (unsigned i = 1; i < counter; i++) {

    third = (first + second) % mod;
    first = second;
    second = third;
  }

  return third;
}
