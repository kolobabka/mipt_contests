#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
void swap(unsigned long long* x, unsigned long long* y);
unsigned long long gcd(unsigned long long x, unsigned long long y);
int is_prime_t(unsigned n);
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


  //printf ("n = %d\n", sieve->n);

  fill_sieve (sieve);

  // for (int i = 0; i < 8; i++)
  //   printf ("%d ", (sieve->s[0] >> i) & 1u);

  // for (int i = 7; i >= 0; i--)
  //   printf ("%d ", sieve->mod1[1] >> i &1);

  // printf ("\n");

  // printf ("%X\n", sieve->mod1[1]);

  printf ("is_prime = %d\n", is_prime (sieve, 2017));

  // for (int j = 0; j < sieve->n; j++)
  // { 
  //   for (int i = 0; i < 8; i++)
  //   {
  //     //printf ("%d\n", 6*(8 * j + i) + 1);

  //     if (!(is_prime_t (6*(8 * j + i) + 1)) != (sieve->mod1[j] >> i & 1) || !(is_prime_t (6*(8 * j + i) + 5)) != (sieve->mod5[j] >> i & 1) )
  //     {
  //       printf ("pidoras nayden!\n");
  //       printf ("\t\tNUM = %d\n\t\t", (6*(8 * j + i) + 1));
  //       printf ("j = %d, i = %d\n", j, i);

  //       return 0;
  //     }
  //   }

  //   for (int i = 7; i >= 0; i--)
  //     printf ("%d ", sieve->mod1[j] >> i &1);
    
  //   printf ("\n");
  // }
  

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
    // printf ("i = %d\n", i);
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

        // if (b / 8 == 22 && (j / 6) % 8 == 1)
        //   printf ("auff1 %d\n", i);
      }

      for (unsigned long long j = 5 * i; j < lim; j += 6 * i)
      {
        // printf ("j2 = %d, i = %d, j = %d\n", j, i, j);
        
        b = j / 6;
        p_5[b / 8] |= (1 << (j / 6) % 8);

        // if (b / 8 == 22 && (j / 6) % 8 == 1)
        //   printf ("auff2 %d\n", i);
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
        // printf ("j4 = %d, i = %d, j = %d\n", j, i, j);
        
        b = j / 6;
        p_1[b / 8] |= (1 << (j / 6) % 8);

        // if (b / 8 == 22 && (j / 6) % 8 == 1)
        //   printf ("auff4 %d\n", i);
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

int is_prime_t(unsigned n)
{
  int last = 0;
  if ((n == 2) || (n == 3))
    return 1;
  if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0))
    return 0;
  last = (int) sqrt(n) + 1;
  for (int j = 5; j <= last; j += 6)
    if (((n % j) == 0) || ((n % (j + 2)) == 0))
      return 0;
  return 1;
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------