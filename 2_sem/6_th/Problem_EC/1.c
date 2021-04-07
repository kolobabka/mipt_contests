#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

double** Matrix_Generate (double** matrix, int N);
void Print_Matrix (int size, double** matrix);
double** Mult_Matrix (double** res_matrix, double** matrix, int N, int P);

int main ()
{
  int check = 0;
  int P = 0;
  int N = 0;
  double** matrix_1 = NULL;
  double** matrix_2 = NULL;
  double** res_matrix = NULL;

  check = scanf ("%d%d", &P, &N);
  assert (check == 2);

  matrix_1 = (double**) calloc (N, sizeof (double*));
  assert (matrix_1);

  matrix_2 = (double**) calloc (N, sizeof (double*));
  assert (matrix_2);

  for (int i = 0; i < N; i++)
  {
    matrix_1[i] = (double*) calloc (N, sizeof (double));
    assert (matrix_1[i]);
  }

  for (int i = 0; i < N; i++)
  {
    matrix_2[i] = (double*) calloc (N, sizeof (double));
    assert (matrix_2[i]);
  }

  matrix_1 = Matrix_Generate (matrix_1, N);

  Print_Matrix (N, matrix_1);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      matrix_2[i][j] = matrix_1[i][j];

  Print_Matrix (N, matrix_2);

  res_matrix = Mult_Matrix (matrix_1, matrix_2, N, P);

  Print_Matrix (N, res_matrix);

  free (matrix_1);
  free (matrix_2);
  free (res_matrix);
}

double** Matrix_Generate (double** matrix, int N)
{
  int check = 0;
  assert (matrix);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      check = scanf ("%lg", matrix[i] + j);
      assert (check == 1);
    }
  }

  return matrix;
}

void Print_Matrix (int size, double** matrix)
{
  assert (matrix);

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf ("%lg ", matrix[i][j]);
    }
    printf("\n");
  }
}

double** Mult_Matrix (double** matrix_1, double** matrix_2, int N, int P)
{
  int counter = 0;
  double** res_matrix = NULL;
  double tmp = 0;
  assert (matrix_1);
  assert (matrix_2);

  res_matrix = (double**) calloc (N, sizeof (double*));

  for (int i = 0; i < N; i++)
    res_matrix[i] = (double*) calloc (N, sizeof (double));

    printf("%lg\n", matrix_1[0][0]);
    printf("%lg\n", matrix_1[0][1]);
    printf("%lg\n", matrix_2[0][0]);
    printf("%lg\n", matrix_2[0][1]);

  while (counter < P)
  {
    for (int k = 0; k < N; k++)
    {
      for (int j = 0; j < N; j++)
      {
        for (int i = 0; i < N; i++)
        {
          tmp = matrix_1[j][i] * matrix_2[i][k] + tmp;
        }
        res_matrix[j][k] = tmp;
        tmp = 0;
      }
    }
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        matrix_1[i][j] = res_matrix[i][j];

    counter++;
  }

  return res_matrix;
}
