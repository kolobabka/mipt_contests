#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
#define N 3
//..............................................................................
//..............................................................................
void Mul_Matrix_Mode (unsigned (*A)[N], unsigned** matrix,unsigned** res_matrix, unsigned m);
void Mul_Matrix_2 (unsigned (*A)[N], unsigned (*B)[N], unsigned m);
void powNxN (unsigned (*A)[N], unsigned k, unsigned m);
void Delete_Matrix (unsigned** matrix);
void Id_M_Create (unsigned** matrix);
void Print_Matrix (unsigned (*A)[N]);
void Fill_Matrix (unsigned (*A)[N]);
unsigned** Create_Matrix ();
//..............................................................................
//..............................................................................
int main () {

  unsigned k = 0;
  unsigned m = 0;
  unsigned matrix[N][N];

  //Id_M_Create (id_matrix);

  scanf ("%u%u", &k, &m);



  // matrix = (unsigned (*)[N]) calloc (N, sizeof (unsigned*));
  // assert (matrix);

  Fill_Matrix (matrix);

  powNxN (matrix, k, m);

  // Mul_Matrix_Mode (matrix, id_matrix, res_matrix, 4);
  // for (int i = 0; i < N; i++)
  // {
  //   for (int j = 0; j < N; j++)
  //     printf("%d ", id_matrix[i][j]);
  //
  //   printf("\n");
  // }
  Print_Matrix (matrix);

  //free (matrix);
}
//..............................................................................
//..............................................................................
void Fill_Matrix (unsigned (*A)[N]) {

  assert (A);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", &(A[i][j]));
}
//..............................................................................
//..............................................................................
void Print_Matrix (unsigned (*A)[N]) {

  assert (A);

  for (int i = 0; i < N; i++) {

    for (int j = 0; j < N; j++) {

      printf ("%d ", A[i][j]);
    }
    printf("\n");
  }
}
//..............................................................................
//..............................................................................
void powNxN (unsigned (*A)[N], unsigned k, unsigned m) {

  unsigned** id_matrix = NULL;
  unsigned** res_matrix = NULL;
  assert (A);

  id_matrix = Create_Matrix ();
  res_matrix = Create_Matrix ();

  Id_M_Create (id_matrix);

  while (k != 0) {

    if ( (k % 2) == 1) {

      Mul_Matrix_Mode (A, id_matrix, res_matrix, m);
      Mul_Matrix_2 (A, A, m);

      k = k / 2;
    }
    else {

      Mul_Matrix_2 (A, A, m);

      k = k / 2;
    }
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      A[i][j] = res_matrix[i][j];

  Delete_Matrix (id_matrix);
  Delete_Matrix (res_matrix);
}
//..............................................................................
//..............................................................................
void Id_M_Create (unsigned** matrix) {

  int j = 0;
  assert (matrix);

  for (int i = 0; i < N; i++) {

    matrix[i][j] = 1;
    j++;
  }
}
//..............................................................................
//..............................................................................
void Mul_Matrix_Mode (unsigned (*A)[N], unsigned** matrix,unsigned** res_matrix, unsigned m) {

  int tmp = 0;
  assert (matrix);
  assert (A);

  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        tmp =  (tmp + (A[i][j] * matrix[j][k])) % m;
      }
      res_matrix[i][k] = tmp;
      tmp = 0;
    }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      matrix[i][j] = res_matrix[i][j];
}
//..............................................................................
//..............................................................................
unsigned** Create_Matrix () {

  unsigned** matrix = NULL;

  matrix = (unsigned**) calloc (N, sizeof (unsigned*));
  assert (matrix);

  for (int i = 0; i < N; i++) {

    matrix[i] = (unsigned*) calloc (N, sizeof (unsigned));
    assert (matrix[i]);
  }

  return matrix;
}
//..............................................................................
//..............................................................................
void Mul_Matrix_2 (unsigned (*A)[N], unsigned (*B)[N], unsigned m) {

  unsigned** res_matrix = NULL;
  int tmp = 0;
  assert (A);

  res_matrix = Create_Matrix ();

  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        tmp =  (tmp + (A[i][j] * B[j][k])) % m;
      }
      res_matrix[i][k] = tmp;
      tmp = 0;
    }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      A[i][j] = res_matrix[i][j];

  Delete_Matrix (res_matrix);
}
//..............................................................................
//..............................................................................
void Delete_Matrix (unsigned** matrix) {

  assert (matrix);

  for (int i = 0; i < N; i++)
    free (matrix[i]);

  free (matrix);
}
