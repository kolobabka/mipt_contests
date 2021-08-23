#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
//..............................................................................
//..............................................................................
int gcd (int a, int b);
void gcdext (int a, int b, int *d, int *x, int *y);
//..............................................................................
//..............................................................................
int main () {

  int a = 0, b = 0, c = 0;
  int res = 0;
  int x = 0, y = 0;
  int k = 0;

  assert ((scanf("%d%d%d", &a, &b, &c)) == 3);

  res = gcd (a, b);

  if ( (c % res) != 0) {

    printf("NONE\n");
    return 0;
  }

  if (a > b)
    gcdext (a, b, &res, &x, &y);
  else
    gcdext (b, a, &res, &y, &x);


  k = c / res;

  x *= k;
  y *= k;


  printf ("%d %d\n", x, y);
}
//..............................................................................
//..............................................................................
int gcd (int a, int b) {

  int reminder;

  a = abs (a);
  b = abs (b);

  if (b > a)
    return gcd(b, a);

  reminder = a % b;

  if (reminder == 0)
    return b;
  return gcd(b, reminder);
}
//..............................................................................
//..............................................................................
void gcdext (int a, int b, int *res, int *x, int *y) {

  int tmp = 0;

  if (b == 0) {

    *res = a;
    *x = 1;
    *y = 0;

    return;
  }

  gcdext(b,a % b,res,x,y);

  tmp = *y;

  *y = *x - ((a / b) * (*y));
  *x = tmp;
}
