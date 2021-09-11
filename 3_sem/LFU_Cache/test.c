#include <stdio.h>

typedef struct object {
  int n;
  int (*prop)();
} object;

int prop(int n)
  {
    return 64+n;
  };

int main(void)
{
  
  struct object obj = {26, &prop};
  printf("%d\n", obj.prop(obj.n));
  return 0;
}

