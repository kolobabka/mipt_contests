#include <stdio.h>
#include <stdlib.h>
#include <math.h>

constexpr int N = 100;
struct Decimal {
char a[N]; // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
unsigned int n; // наибольшая степень десяти
};

Decimal zero = {{0}, 0}; // представление числа 0 в виде структуры

int main ()
{
Decimal a = {{7, 4, 1}, 2}; // set number 147

Decimal res = mult_int(a, 11); // res = a*11 = 147*11 = 1617

print(res); // print 1617

}

Decimal mult_int (const Decimal& a, unsigned int x)
{
  unsigned res = 0;
  for (int i = 0; i <= a.n, i++)
  {
    res += a.N[i]*pow(10, i);
  }
  return res;
}
