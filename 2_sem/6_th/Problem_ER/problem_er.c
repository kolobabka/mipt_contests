#include <stdio.h>
#include <fenv.h>
#include <math.h>
#include <assert.h>

unsigned as_uint(float f)
{
  return *(unsigned *) &f;
}

int main ()
{
  float d_0 = 0;
  int a = 0;
  int b = 0;
  float res = 0;
  int check = 0;
  unsigned mask_15 = 0;
  unsigned mask_7 = 0;
  unsigned tmp = 0u;

  scanf ("%d%d", &a, &b);

  d_0 = a / b;

  mask_15 = 15;
  mask_7 = 7;

  // fesetround(FE_UPWARD); assert (as_uint(a / b) == 0x3eaaaaab);
  // fesetround(FE_TONEAREST); assert (as_uint(a / b) == 0x3eaaaaab);
  // fesetround(FE_TOWARDZERO); assert (as_uint(a / b) == 0x3eaaaaaa);
  fesetround(FE_TOWARDZERO);

  d_0 = (float) a / b;

  tmp = *((unsigned*) (&d_0));

  printf ("0x%x", (tmp & (mask_15 << 27)) >> 27);
  printf ("%x ", (tmp & (mask_15 << 23)) >> 23);


  printf ("0x%x", (tmp & (mask_7 << 20)) >> 20);

  for (int i = 4; i >= 0; i--)
  {

  printf ("%x", (tmp & (mask_15 << 4*i)) >> 4*i);

  }
  printf(" ");

  // if(d_0 > 0)
  //   fesetround(FE_UPWARD);
  // else
  //   fesetround(FE_DOWNWARD);

  fesetround(FE_TONEAREST);         TODO: normal printf axaxxaaxxa lovi v ebalo 

  d_0 = (float) a / b;

  tmp = *((unsigned*) (&d_0));

  printf ("0x%x", (tmp & (mask_15 << 27)) >> 27);
  printf ("%x ", (tmp & (mask_15 << 23)) >> 23);


  printf ("0x%x", (tmp & (mask_7 << 20)) >> 20);

  for (int i = 4; i >= 0; i--)
  {

  printf ("%x", (tmp & (mask_15 << 4*i)) >> 4*i);

  }

  printf("\n");
  //res = nextafterf(d_0, d_0 + 1.0f);
  //printf("%.8f", d_1 - d_0);
}
