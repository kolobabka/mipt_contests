#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//..............................................................................
//..............................................................................
int Editing_Distance (int** matrix, char str_1[], char str_2[], int len_1, int len_2);
int Minimum (int** matrix, char str_1[], char str_2[], int i, int j);
void Free_Matrix (int** matrix, int len_1, int len_2);
void Fill_Str (char str_1[], char str_2[]);
int** Init_Matix (int len_1, int len_2);
//..............................................................................
//..............................................................................
int main ()
{
  int len_1 = 0, len_2 = 0, res = 0, tmp = 0;
  int** matrix = NULL;
  char str_1[101] = {};
  char str_2[101] = {};

  Fill_Str (str_1, str_2);

  len_1 = strlen (str_1);
  len_2 = strlen (str_2);

  if (len_2 < len_1)
  {
    matrix = Init_Matix (len_2, len_1);
    res = Editing_Distance (matrix, str_2, str_1, len_2, len_1);
  }
  else
  {
    matrix = Init_Matix (len_1, len_2);
    res = Editing_Distance (matrix, str_1, str_2, len_1, len_2);
  }


  printf("%d\n", res);

  if (len_2 > len_1)
    Free_Matrix (matrix, len_1, len_2);
  else
    Free_Matrix (matrix, len_2, len_1);

  return 0;
}
//..............................................................................
//..............................................................................
void Fill_Str (char str_1[], char str_2[])
{
  int c = 0, index = 0;

  while ( (c = getchar ()) != '\n' )
  {
    str_1[index] = c;
    index++;
  }

  str_1[index] = '\0';
  c = index = 0;

  while ( (c = getchar ()) != '\n' )
  {
    str_2[index] = c;
    index++;
  }

  str_2[index] = '\0';
}
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
int Editing_Distance (int** matrix, char str_1[], char str_2[], int len_1, int len_2)
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
      matrix[i][j] = Minimum (matrix, str_1, str_2, i, j);
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
int Minimum (int** matrix, char str_1[], char str_2[], int i, int j)
{
  assert (matrix);
  int first = 0, second = 0, third = 0;
  int min = 0;

  first = matrix[i - 1][j] + 1;
  second = matrix[i][j - 1] + 1;

  if (str_1[j - 1] == str_2[i - 1])
    third = matrix[i - 1][j - 1];
  else
    third = matrix[i - 1][j - 1] + 1;

  min = first;

  if (min > second)
    min = second;

  if (min > third)
    min = third;

  return min;
}
