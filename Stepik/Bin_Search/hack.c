#include <stdio.h>
//..............................................................................
//..............................................................................
int main ()
{
  int arr[3] = {1, 2, 3};
  int Arr[4] = {4, 5, 6, 7};

  printf ("Arr[%d] = %d\n", 0, Arr[0]);

  arr[3] = 1;
  arr[1488] = 666;
  //
  printf ("Arr[%d] = %d\n", 1, Arr[1]);
}
