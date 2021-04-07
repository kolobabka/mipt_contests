

typedef int (*generator_t)(int);

unsigned cycle_len(generator_t gen)
{
  int num = -1;
  int tmp = 0;
  int res = 0;
  int counter = 0;

  res = gen (res);
  tmp = res;

  while (num != tmp)
  {
    num = gen (res);
    counter++;
    res = num;
  }

  return counter;
}
