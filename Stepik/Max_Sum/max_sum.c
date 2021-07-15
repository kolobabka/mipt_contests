#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
typedef struct result {

  int num;
  int* terms;

} Result;
//..............................................................................
//..............................................................................
Result* Max_Sum (int number);
void Print_Struct (Result* result);
void Free_Func (Result* result);
//..............................................................................
//..............................................................................
int main ()
{
  int number = 0, check = 0;
  Result* result = NULL;

  check = scanf ("%d", &number);
  assert (check == 1);

  result = Max_Sum (number);

  Print_Struct (result);

  Free_Func (result);

  return 0;
}
//..............................................................................
//..............................................................................
Result* Max_Sum (int number)
{
  int cur_sum = 0, iterator = 1;
  int counter = 0;
  Result* result = NULL;

  result = (Result*) calloc (1, sizeof (Result));
  assert (result);

  result->terms = (int*) calloc (number, sizeof (int));
  assert (result->terms);

  while (cur_sum < number)
  {
    cur_sum += iterator;
    result->terms[counter] = iterator;
    counter++;
    iterator++;


    if (cur_sum > number)
    {
      counter--;
      cur_sum = cur_sum - iterator - result->terms[counter - 1] + 1;
      result->terms[counter - 1] = number - cur_sum;
      //printf("counter = %d\ncur_sum = %d\niterator = %d\n", counter, cur_sum, iterator);
      result->num = counter;

      return result;
    }

    if (cur_sum == number)
    {
      result->num = counter;

      return result;
    }
  }
  return result;
}
//..............................................................................
//..............................................................................
void Print_Struct (Result* result)
{
  assert (result);

  printf("%d\n", result->num);
  
  for (int i = 0; i < result->num; i++)
    printf ("%d ", result->terms[i]);
}
//..............................................................................
//..............................................................................
void Free_Func (Result* result)
{
  assert (result);
  free (result->terms);
  free (result);
}
//..............................................................................
//..............................................................................
