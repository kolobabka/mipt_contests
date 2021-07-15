#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
//..............................................................................
//..............................................................................
typedef struct item {

  int cost;
  int weight;

} Item;

const double EPSILON = 0.000000001;
//..............................................................................
//..............................................................................
void Fill_Items (Item* items, int num);
double Max_Cost (Item* items, int num, int weight);
void Print_Items (Item* Items, int num);
int Compare (const void* Item_1, const void* Item_2);
//..............................................................................
//..............................................................................
int main ()
{
  int num = 0, check = 0, weight = 0;

  check = scanf ("%d%d", &num, &weight);
  assert (check == 2);

  Item* items = (Item*) calloc (num, sizeof (Item));
  assert (items);

  Fill_Items (items, num);
  qsort (items, num, sizeof (Item), Compare);

  // printf("\t\t\t************\n");
  // Print_Items (items, num);

  double result = Max_Cost (items, num, weight);

  printf("%.3lf\n", result);

  free (items);
}
//..............................................................................
//..............................................................................
void Fill_Items (Item* items, int num)
{
  assert (items);
  int check = 0;

  for (int i = 0; i < num; i++)
  {
    check = scanf ("%d%d", &((items + i)->cost), &((items + i)->weight));
    assert (check == 2);
  }
}
//..............................................................................
//..............................................................................
double Max_Cost (Item* items, int num, int max_weight)
{
  assert (items);
  int weight = 0;
  double cost = 0;

  for (int i = 0; i < num; i++)
  {
    if (weight == max_weight)
      return cost;
    if (weight + items[i].weight <= max_weight)
    {

      if (items[i].cost == 0)
        continue;

      cost += items[i].cost;
      weight += items[i].weight;
      // printf("cost = %f\n", cost);
      // printf("weight = %d\n", weight);

      if (weight == max_weight)
        return cost;
    }
    else
    {
      cost += (double) ( ((double) items[i].cost) / ((double) (items[i].weight))) * (max_weight - weight);
      weight += max_weight - weight;
    }
  }
  return cost;
}
//..............................................................................
//..............................................................................
int Compare (const void* Item_1, const void* Item_2)
{
  assert (Item_1);
  assert (Item_2);

  Item* First = (Item*) Item_1;
  Item* Second = (Item*) Item_2;

  double res_1 = (double) ( double (First->cost) / double (First->weight) );
  double res_2 = (double) (double (Second->cost) / double (Second->weight) );

  // printf("res_1 = %lf\n", res_1);
  // printf("res_2 = %lf\n", res_2);

  // printf("cost = %f\n", First->cost);
  // printf("weight = %d\n", weight);

  //if ( (double)( ( (double) (First->cost / First->weight)) - ( (double)(Second->cost / Second->weight)) ) < EPSILON )
  if (res_1 - res_2 < EPSILON)
    return 1;
  else
    return -1;
}
//..............................................................................
//..............................................................................
void Print_Items (Item* Items, int num)
{
  assert (Items);

  for (int i = 0; i < num; i++)
    printf("%d %d\n", Items[i].cost, Items[i].weight);
}
