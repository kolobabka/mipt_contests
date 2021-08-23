#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//..............................................................................
//..............................................................................
int next_turn (int total, int possible);
int Fib_Close (int x, int* fib_num);
int* Fib_System (int x, int* len);
int Fib_Number (int fib_num);
void Start_Play (int num);
int Fib_Count (int x);
//..............................................................................
//..............................................................................
int main () {

  int num = 0;
  assert ( (scanf("%d", &num)) == 1);

  Start_Play (num);

  return 0;
}
//..............................................................................
//..............................................................................
void Start_Play (int num) {

  int amount = 0;
  int reminder = 0;
  int possible = 0;
  int player = 0;

  reminder = num;
  possible = num - 1;
  printf("num = %d\n", num);

  while (reminder > 0) {

    amount = next_turn (reminder, possible);
    reminder -= amount;
    possible = amount * 2;

    printf("  player: %d\n", player);
    printf("amount = %d\n", amount);
    printf("reminder = %d\n", reminder);

    player = (player + 1) % 2;
  }
}
//..............................................................................
//..............................................................................
int next_turn (int total, int possible) {

  int* fib_arr = NULL;
  int sticks = 0;
  int fib = 0;
  int len = 0;
  int fib_num = -666;

  fib_arr = Fib_System (total, &len);

  if (possible >= total)
    return total;

  for (int i = 0; i < len; i++) {

    if (fib_arr[i] == 1 && i != len - 1) {

      fib_num = i;
      break;
    }
  }

  free (fib_arr);

  if (fib_num == -666)
    return 1;

  sticks = Fib_Number (fib_num);

  // printf("fib_num = %d\nsticks = %d\n", fib_num, sticks);
  // exit (1);
  if (sticks <= possible)
    return sticks;
  else
    return 1;

}
//..............................................................................
//..............................................................................
int* Fib_System (int x, int* len) {

  int* arr = NULL;
  int fib_num = 0;
  int fib_close = 0;

  fib_num = Fib_Count (x);
  *len = fib_num;

  arr = (int*) calloc (fib_num, sizeof (int));
  assert (arr);

  while (x) {


    fib_close = Fib_Close (x, &fib_num);
    arr[fib_num] = 1;

    if (fib_close == x)
      break;

    x -= fib_close;
  }



  return arr;
}
//..............................................................................
//..............................................................................
int Fib_Count (int x) {

  int res = 1;
  int first = 1;
  int second = 2;
  int third = 0;

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
int Fib_Close (int x, int* fib_num) {

  int first = 1;
  int second = 2;
  int third = 0;

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
//..............................................................................
//..............................................................................
int Fib_Number (int fib_num) {

  int first = 1;
  int second = 2;
  int third = 0;

  if (fib_num == 0)
    return 1;
  if (fib_num == 1)
    return 2;

  for (int i = 2; i <= fib_num; i++)
  {
    third = first + second;
    first = second;
    second = third;
  }

  return third;
}
//..............................................................................
//..............................................................................
