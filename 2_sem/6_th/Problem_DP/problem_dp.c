#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <float.h>
//..............................................................................
typedef struct {
  int col;
  int row;
  double max;
} max_t;
//..............................................................................
void Print_Matrix (int size, double** matrix);
double** Rand_Matrix_Generate (int size, double** matrix);
double** Matrix_Generate (int det, int size, double** matrix);
double** swap_columns (double** matrix, int current, max_t elem, int size);
double** swap_rows(double** matrix, int current, max_t elem, int size);
max_t max_submatrix_element(double** matrix, int current, int size);
double** eliminate(double** matrix, int current, int size);
int Det_Matrix (double** matrix, int size);
//..............................................................................
//..............................................................................
int main ()
{
  int det = 5;
  int size = 10;
  double** matrix = NULL;
  max_t elem = {};
  int flag = 0;
  int sign = 0;

  // srand (time (NULL) );

  scanf("%d", &size);

  matrix = (double**) calloc (size, sizeof (double*));
  assert (matrix);

  for (int i = 0; i < size; i++)
  {
    matrix[i] = (double*) calloc (size, sizeof (double));
    assert (matrix[i]);
  }

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      scanf("%lg", &matrix[i][j]);

  // matrix = Matrix_Generate (det, size, matrix);
  // matrix = Rand_Matrix_Generate (size, matrix);

  Print_Matrix (size, matrix);


  //
  //
  //
  // //Print_Matrix (size, matrix);
  //

  //
  // // printf("Max element = %lg\n"
  // //        "Col = %d\nRow = %d\n", elem.max, elem.col, elem.row);
  //



  // Print_Matrix (size, matrix);
  //
#if 1
  for (int i = 0; i < size; i++)
  {
    elem = max_submatrix_element (matrix, i, size);


    matrix = swap_columns (matrix, i, elem, size);
    if (elem.col != i)
      sign++;
    elem.col = i;
    printf("\t\t\tAFTER SWAP_COL\n");
    Print_Matrix (size, matrix);
    matrix = swap_rows (matrix, i, elem, size);
    if (elem.row != i)
      sign++;
    elem.row = i;
     printf("\t\t\tAFTER SWAP_ROWS\n");
    Print_Matrix (size, matrix);

    //Print_Matrix (size, matrix);
    //printf("\n\n");

    if (matrix[i][i] == 0)
      break;

    matrix = eliminate (matrix, i, size);
    // Print_Matrix (size, matrix);
    // printf("\n\n");

    flag++;
  }

  if (flag < size)
  {
    printf("%d", 0);
  }
  else
  {
    if (sign % 2 == 0)
      printf("%d\n", Det_Matrix (matrix, size));
    else
      printf("%d\n", -Det_Matrix (matrix, size));
  }


  for (int i = 0; i < size; i++)
  {
    free (matrix[i]);
  }
  free (matrix);
#endif
}

double** Matrix_Generate (int det, int size, double** matrix)
{
  int j = 0;
  for (int i = 0; i < size; i++)
  {
    j = i;
    for (j; j < size; j++)
    {
      if (j == i)
        matrix[i][j] = 1;
      else
        matrix[i][j] = rand () % 100;
    }
    if (i == size - 1)
      matrix[i][j - 1] = det;
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
double** Rand_Matrix_Generate (int size, double** matrix)
{
  double rand_elem = 0;

  for (int i = 0; i < size; i++)
  {
    rand_elem = rand () % 100;
    for (int j = 0; j < size; j++)
    {
      if (i == 0)
        break;

      matrix[i][j] += matrix[0][j] * rand_elem;
      // if (j == 0)
      // {
      //   printf("matrix[%d][0] = %d\n"
      //          "*matrix[1][%d] = %d\n", i, matrix[i][j], j, matrix[1][j] * rand_elem);
      // }
    }
  }
  for (int j = 0; j < size; j++)
  {

    matrix[0][j] += matrix[size-1][j] * rand_elem;

  }
  return matrix;
}

double** Max_Matrix_View (int size, double** matrix)
{

  int i_max = 0;
  int j_max = 0;

  for (int i = 0; i < size; i++)
  {
    for (int k = 0; k < size; k++)
    {
      for (int j = 0; j < size; j++)
      {
        if (matrix[i_max][j_max] < matrix[k][j])
        {
          i_max = k;
          j_max = j;
        }
      }
    }
  }


  return matrix;
}

double** swap_columns (double** matrix, int current, max_t elem, int size)
{
  double tmp = 0.0;

  for (int i = current; i < size; i++)
  {
    tmp = matrix[i][current];
    matrix[i][current] = matrix[i][elem.col];
    matrix[i][elem.col] = tmp;
  }
  return matrix;
}

double** swap_rows(double** matrix, int current, max_t elem, int size)
{
  double tmp = 0.0;

  for (int i = current; i < size; i++)
  {
    tmp = matrix[current][i];
    matrix[current][i] = matrix[elem.row][i];
    matrix[elem.row][i] = tmp;
  }
  return matrix;
}

max_t max_submatrix_element(double** matrix, int current, int size)
{
  max_t elem = {};

  elem.max = matrix[current][current];
  elem.row = current;
  elem.col = current;

  assert (matrix);
  assert (size);

  for (int i = current; i < size; i++)
  {
    for (int j = current; j < size; j++)
    {
      if (fabs (elem.max) <= fabs (matrix[i][j]))
      {
        elem.max = matrix[i][j];
        elem.row = i;
        elem.col = j;
      }
    }
  }
  return elem;
}

double** eliminate(double** matrix, int current, int size)
{
  double coeff = 0.0;
  assert (matrix);
  assert (matrix[current]);
  assert (matrix[current][current]);

  for (int i = current + 1; i < size; i++)
  {
    coeff = matrix[i][current] / matrix[current][current];

    for (int j = current; j < size; j++)
    {
      matrix[i][j] -= matrix[current][j] * coeff;

    }
  }

  return matrix;
}

int Det_Matrix (double** matrix, int size)
{
  double det = 1;
  assert (matrix);
  for (int i = 0; i < size; i++)
  {
    // if (matrix[i][i] > -10E-1 && matrix[i][i] < 0)
    //   matrix[i][i] = -matrix[i][i];
    //printf("%lg \n", matrix[i][i]);
    det *= matrix[i][i];
  }
  if (det > 0)
    det += 0.5;
  else
    det -= 0.5;

  return  (int) det;
}
