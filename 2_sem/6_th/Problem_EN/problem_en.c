#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <float.h>
#include <assert.h>
#include <stdlib.h>
//..............................................................................
struct func_deriv {
  double func;
  double der;
};
//..............................................................................
//..............................................................................
//..............................................................................
double polyroot(double *coeffs, int degree);
//..............................................................................
int main ()
{
  double* arr = NULL;
  int n = 0;
  double x = 0;

  scanf("%d", &n);

  arr = (double*) calloc (n + 1, sizeof (double));
  assert (arr);

  for (int i = 0; i <= n; i++)
    scanf("%lg", arr + i);

  x = polyroot (arr, n);

  printf("%.6lg\n", x);

}
//..............................................................................
double polyroot(double *coeffs, int degree)
{
  struct func_deriv inf = {0, 0};
  int counter = 0;

  double x = 100;

  for (int i = 0; i <= degree; i++)
  {
    inf.func = inf.func + (coeffs[i] * pow (x, i));
  }
  for (int i = 0; i <= degree - 1; i++)
  {
    inf.der = inf.der + coeffs[i + 1] * pow (x, i) * (i + 1);
  }

  while (fabs (inf.func) > 0.00001)
  {
    counter++;
    if (counter > 10000)
      return 0;

    x = x - (inf.func / inf.der);

    inf.func = 0;
    inf.der = 0;

    for (int i = 0; i <= degree; i++)
    {
      inf.func = inf.func + (coeffs[i] * pow (x, i));
    }
    for (int i = 0; i <= degree - 1; i++)
    {
      inf.der = inf.der + coeffs[i + 1] * pow (x, i) * (i + 1);
    }
  }

  return x;
}
//..............................................................................
