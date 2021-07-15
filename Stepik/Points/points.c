#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
typedef struct point {

  int first;
  int second;

} Point;
//..............................................................................
//..............................................................................
int Counter (Point* points, int num);
void Fill_Points (Point* points, int num);
int Compare (const void* Point_1, const void* Point_2);
void Print_Points (Point* points, int num);
//..............................................................................
//..............................................................................
int main ()
{

  int num = 0, result = 0;
  scanf ("%d", &num);

  Point* points = (Point*) calloc (num, sizeof (Point));
  assert (points);

  Fill_Points (points, num);
  qsort (points, num, sizeof (Point), Compare);

  result = Counter (points, num);

  printf("%d \n", result);

  for (int i = 0; i < result; i++)
    printf("%d ", points[i].first);

  printf("\n");

  free (points);

  return 0;

}

void Fill_Points (Point* points, int num)
{
  assert (points);
  int check = 0;

  for (int i = 0; i < num; i++)
  {
    check = scanf ("%d%d", &((points + i)->first), &((points + i)->second));
    assert (check == 2);
  }
}

int Compare (const void* Point_1,const void* Point_2)
{
  assert (Point_1);
  assert (Point_2);

  Point* First = (Point*) Point_1;
  Point* Second = (Point*) Point_2;

  return (First->second - Second->second);
}

void Print_Points (Point* points, int num)
{
  assert (points);

  for (int i = 0; i < num; i++)
    printf("%d %d\n", points[i].first, points[i].second);
}

int Counter (Point* points, int num)
{
  assert (points);

  int counter = 1;
  int index = 0;
  points[0].first = points[0].second;
  for (int i = 1; i < num; i++)
  {
    if (points[index].second >= points[i].first)
      continue;
    else
    {
      index = i;
      counter++;
      points[counter - 1].first = points[index].second;
    }
  }
  return counter;

}
