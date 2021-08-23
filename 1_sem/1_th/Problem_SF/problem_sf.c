#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//..............................................................................
//..............................................................................
unsigned Fib_Close (unsigned x, unsigned* fib_num);
unsigned Fib_Count (unsigned x);
void Fib_System (unsigned x);
//..............................................................................
//..............................................................................
int main () {

  unsigned x = 0;

  assert ( (scanf("%u", &x)) == 1);

  Fib_System (x);
}
//..............................................................................
//..............................................................................
void Fib_System (unsigned x) {

  unsigned* arr = NULL;
  unsigned fib_num = 0;
  unsigned fib_close = 0;
  unsigned len = 0;

  fib_num = Fib_Count (x);
  len = fib_num;

  arr = (unsigned*) calloc (fib_num, sizeof (unsigned));
  assert (arr);

  while (x) {


    fib_close = Fib_Close (x, &fib_num);
    arr[fib_num] = 1;

    if (fib_close == x)
      break;

    x -= fib_close;
  }

  for (int i = len - 1; i >= 0; i--)
    printf("%u", arr[i]);

  printf("\n");

  free (arr);
}
//..............................................................................
//..............................................................................
unsigned Fib_Count (unsigned x) {

  unsigned res = 1;
  unsigned first = 1;
  unsigned second = 2;
  unsigned third = 0;

  if (x == 1)
    return 1;
  if (x == 2)
    return 2;
  // if (x == 3)
  //   return 3;

  while (third <= x) {

    third = first + second;
    first = second;
    second = third;

    res++;
  }

  return res;
}
//..............................................................................
//..............................................................................
unsigned Fib_Close (unsigned x, unsigned* fib_num) {

  unsigned first = 1;
  unsigned second = 2;
  unsigned third = 0;

  *fib_num = 0;

  if (x == 1) {

    *fib_num = 0;
    return 1;
  }
  if (x == 2) {

    *fib_num = 1;
    return 2;
  }

  while (third <= x) {

    third = first + second;
    first = second;
    second = third;
    (*fib_num)++;
  }

  return first;
}
