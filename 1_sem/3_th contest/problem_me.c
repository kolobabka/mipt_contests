#include <stdio.h>
#include <stdlib.h>

void fill_arr(int* arr,int len);
int majority_element(const int *parr, int len);
int main()
{
  int* arr;
  int len = 0;
  //int *p = arr;
  scanf("%d", &len);

  arr = (int*) calloc(len, sizeof(int));

  fill_arr(arr, len);

  for (int i = 0; i < len; i++)
  printf("\n%d", arr[i]);
}

void fill_arr(int* arr,int len)
{
  for (int i = 0; i < len; i++)
  scanf("%d", &arr[i]);
}

int majority_element(const int *parr, int len)
{

}
