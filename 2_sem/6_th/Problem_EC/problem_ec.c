#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

//..............................................................................
//..............................................................................
double fsgn (double x);
int secant(double a, double b, double c, double xleft, double xright, double precision);
double f (double a, double b, double c, double x);
int Dih (double a, double b, double c, double xleft, double xright, double precision);
//..............................................................................
//..............................................................................
int main ()
{
  int check = 0;
  int counter_R = 0;
  int counter_D = 0;
  double a = 0, b = 0, c = 0;
  double N = 0;
  double prec = 0;
  double xleft = 0, xright = 0;


  check = scanf ("%lf%lf%lf", &a, &b, &c);
  assert (check == 3);

  check = scanf ("%lf", &N);
  assert (check == 1);

  check = scanf ("%lf", &prec);
  assert (check == 1);

  xleft = -N;
  xright = N;

  counter_R = secant (a, b, c, xleft, xright, prec);
  counter_D = Dih (a, b, c, xleft, xright, prec);

  printf("%d %d\n", counter_D, counter_R);

}
//..............................................................................
//..............................................................................
int secant(double a, double b, double c, double xleft, double xright, double precision)
{
  int counter = 0;
  double xnew = 0, xmid = 0;
  double fl = 0, fr = 0, fm = 0;
  if ( fsgn(f(a, b, c, xleft)) == fsgn(f(a, b, c, xright)))
    return 0.0;
 

  while (fabs(f(a, b, c, xnew)) > precision)
  {
    counter++;
    xmid = (xleft + xright) / 2.0;
    fl = f(a, b, c, xleft);
    fr = f(a, b, c, xright);
    fm = f(a, b, c, xmid);

    xnew = xmid + (xmid-xleft) * fsgn(fl - fr) * fm / sqrt(fm * fm - fl * fr);

    if ( (fsgn (f (a, b, c, xleft) ) ) == (fsgn (f (a, b, c, xnew) )) )
      xleft = xnew;
    else
      xright = xnew;
  }

  return counter;
}

int Dih (double a, double b, double c, double xleft, double xright, double precision)
{
  int counter_D = 0;
  double xnew = 0;
  double root = 0;

  if ( fsgn(f(a, b, c, xleft)) == fsgn(f(a, b, c, xright)))
    return 0.0;

  xnew = xleft;

  while ( fabs (f (a, b, c, xnew) ) > precision)
  {
    counter_D++;
    xnew = (xleft + xright) / 2;
    if ( (fsgn (f (a, b, c, xleft) ) ) == (fsgn (f (a, b, c, xnew) )) )
      xleft = xnew;
    else
      xright = xnew;
  }

  return counter_D;
}

double fsgn (double x)
{
  return signbit(x) ? -1.0 : 1.0;
}

double f (double a, double b, double c, double x)
{
  double res = 0;

  res = a * x * x * sin(x) + b * x *cos(x) + c;

  return res;
}
