#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
struct sieve_t {
  int n;
  unsigned char *s;
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
  int num = 0;
  int check = 0;

  check = scanf ("%d", &num);
  assert (check == 1);

  sieve = (struct sieve_t*) calloc (1, sizeof (struct sieve_t));
  assert (sieve);

  sieve->s = (unsigned char *) calloc (num, sizeof (unsigned char));
  assert (sieve->s);

  sieve->n = num;

  fill_sieve (sieve);

  // for (int i = 0; i < 8; i++)
  //   printf ("%d ", (sieve->s[0] >> i) & 1u);

  printf ("%d\n", is_prime (sieve, 2017));

}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
void fill_sieve(struct sieve_t *sv)
{
  assert (sv);
  assert (sv->s);

  sv->s[0] = sv->s[0] | (1u << 0);
  sv->s[0] = sv->s[0] | (1u << 1);

  for (int i = 0; i < sv->n; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (((sv->s[i] >> j) & 1u) == 1)
      {
        continue;
      }
      else 
      {
        for (int k = (i*8 + j) * 3; k < sv->n * 8; k += 2 * (i*8 + j))
        {
          if ( ((sv->s[k / 8] >> k % 8) & 1u) == 1)
            continue;
          sv->s[k / 8] = sv->s[k / 8] | (1u << k % 8);
        }
      }
    }
  }
}

int is_prime(struct sieve_t *sv, unsigned n)
{
  if ( (((sv->s[n / 8] >> n % 8) & 1u)) == 1)
    return 0;
  
  return 1;
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
