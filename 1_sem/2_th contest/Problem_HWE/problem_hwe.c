#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
struct sieve_t {
  int n;
  unsigned char *mod1;
  unsigned char *mod5;
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
int main ()
{
  struct sieve_t* sieve = NULL;
  unsigned long long num = 0;
  int check = 0;

  check = scanf ("%llu", &num);
  assert (check == 1);

  sieve = (struct sieve_t*) calloc (1, sizeof (struct sieve_t));
  assert (sieve);

  sieve->mod1 = (unsigned char *) calloc (num, sizeof (unsigned char));
  assert (sieve->mod1);

  sieve->mod5 = (unsigned char *) calloc (num, sizeof (unsigned char));
  assert (sieve->mod5);

  sieve->n = num;

  fill_sieve (sieve);

  free (sieve->mod1);
  free (sieve->mod5);
  free (sieve);

}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
void fill_sieve(struct sieve_t *sv)
{
  int step = 4;
  unsigned char * p_1;
  unsigned char * p_5;
  unsigned long long lim;

  p_1 = sv->mod1;
  p_5 = sv->mod5;

  lim = 48 * (sv->n - 1) + 5;
  p_1[0] = 1;

  for (unsigned long long i = 5; i < lim; i += step)
  {
    int b;
    int a = i / 6;
    if (step == 2)
    {
      if (p_1[a / 8] & (1 << a % 8))
      {
        step = 6 - step;
        continue;
      }

      for (unsigned long long j = 7 * i; j < lim; j += 6 * i)
      {
        b = j / 6;
        p_1[b / 8] |= (1 << (j / 6) % 8);
      }

      for (unsigned long long j = 5 * i; j < lim; j += 6 * i)
      {
        b = j / 6;
        p_5[b / 8] |= (1 << (j / 6) % 8);
      }
    }
    else
    {
      if (p_5[a / 8] & (1 << a % 8))
      {
        step = 6 - step;
        continue;
      }

      for (unsigned long long j = 7 * i; j < lim; j += 6 * i)
      {
        b = j / 6;
        p_5[b / 8] |= (1 << (j / 6) % 8);
      }

      for (unsigned long long j = 5 * i; j < lim; j += 6 * i)
      {

        b = j / 6;
        p_1[b / 8] |= (1 << (j / 6) % 8);
      }
    }
    step = 6 - step;
  }
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
int is_prime(struct sieve_t *sv, unsigned n)
{
  int a = 0;
  a = n / 6;
  if (n == 2 || n == 3)
    return 1;

  if (n % 6 != 1 && n % 6 != 5)
    return 0;

  if (n % 6 == 1)
  {
    if (!(sv->mod1[a / 8] & (1 << ((a) % 8))))
    {
      return 1;
    }
    return 0;
  }
  if (n % 6 == 5)
  {
    if (!(sv->mod5[a / 8] & (1 << (n / 6) % 8)))
      return 1;

    return 0;
  }
  return 0;
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
