#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
typedef struct segment {

  int x;
  int y;

} Seg;
//..............................................................................
//..............................................................................
void Checker (Seg* points, int* arr, int num_seg, int num_pts);
void Very_Quick_Sort (Seg* points, int left, int right);
int Very_Partition (Seg* points, int left, int right);
void Quick_Sort (int* points, int left, int right);
int Partition (int* arr, int left, int right);
void Print_Seg (Seg* points, int num_seg);
void Fill_Seg (Seg* points, int num_seg);
void Print_Arr (int* arr, int n);
void Fill_Arr (int* arr, int n);
//..............................................................................
//..............................................................................
int main ()
{
  Seg* points = NULL;
  int* arr = NULL;
  int check = 0;
  int num_seg = 0;
  int num_pts = 0;

  check = scanf ("%d%d", &num_seg, &num_pts);
  assert (check == 2);

  points = (Seg*) calloc (num_seg, sizeof (Seg));
  assert (points);

  arr = (int*) calloc (num_pts, sizeof (int));
  assert (arr);

  Fill_Seg (points, num_seg);
  Fill_Arr (arr, num_pts);

  //Quick_Sort (arr, 0, num_pts - 1);
  Very_Quick_Sort (points, 0, num_seg - 1);

  Checker (points, arr, num_seg, num_pts);

  // Print_Arr (arr, num_pts);
  // Print_Seg (points, num_seg);

  free (arr);
  free (points);
}
//..............................................................................
//..............................................................................
void Quick_Sort (int* arr, int left, int right)
{
  assert (arr);
  int pivot = 0;

  if (left >= right)
    return;

  pivot = Partition (arr, left, right);

  Quick_Sort (arr, left, pivot - 1);
  Quick_Sort (arr, pivot + 1, right);
}
//..............................................................................
//..............................................................................
int Partition (int* arr, int left, int right)
{
  assert (arr);
  int i = 0, j = 0, tmp = 0;
  int elem = 0;

  i = left + 1;
  j = left;

  elem = arr[left];

  for (i; i <= right; i++)
  {
    if (arr[i] > elem)
      continue;
    else
    {
      j++;
      tmp = arr[j];
      arr[j] = arr[i];
      arr[i] = tmp;
    }
  }

  tmp = arr[j];
  arr[j] = arr[left];
  arr[left] = tmp;

  return j;
}
//..............................................................................
//..............................................................................
void Fill_Arr (int* arr, int n)
{
  assert (arr);
  int check = 0;

  for (int i = 0; i < n; i++)
  {
    check = scanf ("%d", arr + i);
    assert (check == 1);
  }
}
//..............................................................................
//..............................................................................
void Print_Arr (int* arr, int n)
{
  assert (arr);

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");
}
//..............................................................................
//..............................................................................
void Fill_Seg (Seg* points, int num_seg)
{
  assert (points);
  int check = 0;

  for (int i = 0; i < num_seg; i++)
  {
    check = scanf ("%d%d", &(points[i].x), &(points[i].y));
    assert (check == 2);
  }
}
//..............................................................................
//..............................................................................
void Print_Seg (Seg* points, int num_seg)
{
  assert (points);

  for (int i = 0; i < num_seg; i++)
    printf("%d %d\n", points[i].x, points[i].y);
}
//..............................................................................
//..............................................................................
void Very_Quick_Sort (Seg* points, int left, int right)
{
  assert (points);
  int pivot = 0;

  if (left >= right)
    return;

  pivot = Very_Partition (points, left, right);

  Very_Quick_Sort (points, left, pivot - 1);
  Very_Quick_Sort (points, pivot + 1, right);
}
//..............................................................................
//..............................................................................
int Very_Partition (Seg* points, int left, int right)
{
  assert (points);
  int i = 0, j = 0, tmp_x = 0, tmp_y = 0;
  int elem = 0;

  i = left + 1;
  j = left;

  elem = points[left].x;

  for (i; i <= right; i++)
  {
    if (points[i].x > elem)
      continue;
    else
    {
      j++;
      tmp_x = points[j].x;
      tmp_y = points[j].y;
      points[j].x = points[i].x;
      points[j].y = points[i].y;
      points[i].x = tmp_x;
      points[i].y = tmp_y;
    }
  }

  tmp_x = points[j].x;
  tmp_y = points[j].y;
  points[j].x = points[left].x;
  points[j].y = points[left].y;
  points[left].x = tmp_x;
  points[left].y = tmp_y;

  return j;
}
//..............................................................................
//..............................................................................
void Checker (Seg* points, int* arr, int num_seg, int num_pts)
{
  assert (points);
  assert (arr);
  int counter = 0;

  for (int i = 0; i < num_pts; i++)
  {
    for (int j = 0; j < num_seg; j++)
      if (arr[i] < points[j].x)
        break;
      else
        if (arr[i] <= points[j].y)
          counter++;

    printf("%d ", counter);
    counter = 0;
  }
  printf("\n");
}
