#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <float.h>
#include <assert.h>

double Equation (double a, double b, double c, double x);

int main ()
{
  int check = 0;
  int counter_D = 0;
  double a = 0;
  double b = 0;
  double c = 0;
  double res_1 = 0;
  double res_2 = 0;
  double root = 0;
  double N_2 = 0;
  double N_1 = 0;
  double prec = 0;

  check = scanf ("%lf%lf%lf%lf%lf", &a, &b, &c, &N_2, &prec);
  assert (check == 5);

  N_1 = -N_2;

  res_1 = (Equation (a, b, c, N_1));
  res_2 = (Equation (a, b, c, N_2));

  if (res_1 * res_2 > 0)
  {
    printf("%.5f\n", 0.0);
    return 0;
  }

  while (fabs (res_1 - res_2) >  prec)
  {
    counter_D++;
    if ((signbit (Equation (a, b, c, (N_1 + N_2) / 2)) == 0 && signbit(res_1) != 0) || (signbit (Equation (a, b, c, (N_1 + N_2) / 2)) != 0 && signbit(res_1) == 0) )
    {
      N_2 = (N_1 + N_2) / 2;
      root = N_2;
    }
    else
    {
      N_1 = (N_1 + N_2) / 2;
      root = N_1;
    }

    res_1 = (Equation (a, b, c, N_1));
    res_2 = (Equation (a, b, c, N_2));

  }

  printf("%.5f\n", root);
  printf("counter = %d\n", counter_D);

}

double Equation (double a, double b, double c, double x)
{
  double res = 0;

  res = a * pow (x,2) * sin(x) + b * x *cos(x) + c;

  return res;
}
