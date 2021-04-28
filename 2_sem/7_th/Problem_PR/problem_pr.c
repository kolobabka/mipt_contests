#include <stdio.h>

float rSqrt (float num);

int main () {

  float num = 2;

  printf ("rsqrt = %lf", rSqrt (num));
}

float rSqrt (float num)
{
  float res;

  asm ("rsqrtss %1, %0" : "=x" (res) : "x" (num));

  return res;
}