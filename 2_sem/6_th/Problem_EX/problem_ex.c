#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main ()
{
  float num = 0;
  int check = 0;
  unsigned* p = NULL;
  int i = 0;

  check = scanf ("%f", &num);
  assert (check == 1);

  p = (unsigned*) &num;

  for (int i = 1; i < 23; i += 2)
  {
    *p = *p ^ (1 << i);
  }


  printf("%.5f\n", num);





}
