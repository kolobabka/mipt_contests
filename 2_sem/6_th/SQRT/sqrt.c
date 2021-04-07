#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

float tests[] = {2, 3, 4, 5, 6, 7, 8, 9};

union dblbits {
  float f;
  unsigned u;
};

float mysqrt (double x)
{
  union dblbits u;
  u.f = x;
  u.u = (u.u >> 1) + (0x3f800000 >> 1);

  return u.f;
}

int main ()
{
  int ntests = sizeof (tests) / sizeof (tests[0]);

  for (int i = 0; i < ntests; i++)
    fprintf (stdout, "%.8f vs %.8f\n");

}
