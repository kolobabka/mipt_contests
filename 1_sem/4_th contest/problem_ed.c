#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//..............................................................................
//..............................................................................

int Editing_Distance (int** matrix, char* str_1, char* str_2, int len_1, int len_2, int add, int del, int sub);
int Minimum (int** matrix, char* str_1, char* str_2, int i, int j, int add, int del, int sub);
void Free_Matrix (int** matrix, int len_1, int len_2);
// void Fill_Str (char str_1[], char str_2[]);
int** Init_Matix (int len_1, int len_2);
//..............................................................................
//..............................................................................
int main ()
{
  int check = 0;
  int len_1 = 0, len_2 = 0, res = 0, tmp = 0;
  int add = 0, del = 0, sub = 0;
  int** matrix = NULL;
  char* str_1 = NULL;
  char* str_2 = NULL;

  check = scanf ("%d%d%d", &add, &del, &sub);
  assert (check == 3);

  check = scanf ("%d", &len_1);
  assert (check == 1);

  str_1 = (char*) calloc (len_1 + 1, sizeof (char));
  assert (str_1);

  check = scanf ("%s", str_1); //ATTENTION!
  assert (check == 1);

  check = scanf ("%d", &len_2);
  assert (check == 1);

  str_2 = (char*) calloc (len_2 + 1, sizeof (char));
  assert (str_2);

  check = scanf ("%s", str_2); //ATTENTION!
  assert (check == 1);

  if (len_2 < len_1)
  {
    matrix = Init_Matix (len_2, len_1);
    res = Editing_Distance (matrix, str_2, str_1, len_2, len_1, add, del, sub);
  }
  else
  {
    matrix = Init_Matix (len_1, len_2);
    res = Editing_Distance (matrix, str_1, str_2, len_1, len_2, add, del, sub);
  }


  printf("%d\n", res);

  if (len_2 > len_1)
    Free_Matrix (matrix, len_1, len_2);
  else
    Free_Matrix (matrix, len_2, len_1);

  free (str_1);
  free (str_2);

  return 0;
}
//..............................................................................
//..............................................................................
// void Fill_Str (char str_1[], char str_2[])
// {
//   int c = 0, index = 0;
//
//   while ( (c = getchar ()) != '\n' )
//   {
//     str_1[index] = c;
//     index++;
//   }
//
//   str_1[index] = '\0';
//   c = index = 0;
//
//   while ( (c = getchar ()) != '\n' )
//   {
//     str_2[index] = c;
//     index++;
//   }
//
//   str_2[index] = '\0';
// }
//..............................................................................
//..............................................................................
int** Init_Matix (int len_1, int len_2)
{
  int** matrix = NULL;

  matrix = (int**) calloc (len_2 + 1, sizeof (int*));
  assert (matrix);

  for (int i = 0; i < len_2 + 1; i++)
  {
    matrix[i] = (int*) calloc (len_1 + 1, sizeof (int));
    assert (matrix[i]);
  }

  return matrix;
}
//..............................................................................
//..............................................................................
void Free_Matrix (int** matrix, int len_1, int len_2)
{
  assert (matrix);

  for (int i = 0; i < len_2 + 1; i++)
    free (matrix[i]);

  free (matrix);
}
//..............................................................................
//..............................................................................
int Editing_Distance (int** matrix, char* str_1, char* str_2, int len_1, int len_2, int add, int del, int sub)
{
  assert (matrix);

  for (int i = 0; i <= len_1; i++)
    matrix[0][i] = i;
  for (int i = 0; i <= len_2; i++)
    matrix[i][0] = i;

  for (int i = 1; i <= len_2; i++)
  {
    for (int j = 1; j <= len_1; j++)
    {
      matrix[i][j] = Minimum (matrix, str_1, str_2, i, j, add, del, sub);
      // if (i == 1 && j == 2)
      // {
      //   printf("str_1 = %c\n", str_1[i - 1]);
      //   printf("str_2 = %c\n", str_2[j - 1]);
      // }
    }
  }

  // for (int i = 0; i <= len_2; i++)
  // {
  //   for (int j = 0; j <= len_1; j++)
  //     printf("%d ", matrix[i][j]);
  //
  //   printf("\n");
  // }

  return matrix[len_2][len_1];
}
//..............................................................................
//..............................................................................
int Minimum (int** matrix, char* str_1, char* str_2, int i, int j, int add, int del, int sub)
{
  int first = 0, second = 0, third = 0;
  int min = 0;

  assert (matrix);

  first = matrix[i - 1][j] + add;
  second = matrix[i][j - 1] + del;

  if (str_1[j - 1] == str_2[i - 1])
    third = matrix[i - 1][j - 1];
  else
    third = matrix[i - 1][j - 1] + sub;

  min = first;

  if (min > second)
    min = second;

  if (min > third)
    min = third;

  return min;
}
