#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
typedef struct alphabet {

  char letter;
  int freq;
  int bytecode;

} Alp;
//..............................................................................
//..............................................................................
typedef struct result {

  int num_let;
  int num_bits;

} Result;
//..............................................................................
//..............................................................................
int Word_Fill (char word[], Alp letters[]);
int Compare (const void* Letter_1, const void* Letter_2);
Result Bytecoder (Alp letters[]);
void Print_Func (Alp letters[], Result result);
void Decoder (char word[], Alp letters[], int len, int num_let);
//..............................................................................
//..............................................................................
int main ()
{
  int len = 0;
  char word[10010] = {};
  Alp letters[26] = { {'\0'}, {0}, {0} };
  Result result = { 0, 0 };

  len = Word_Fill (word, letters);
  qsort (letters, 26, sizeof (Alp), Compare);

  result = Bytecoder (letters);

  Print_Func (letters, result);
  Decoder (word, letters, len, result.num_let);
  // //printf("smth get wrong(\n");
  // printf("len = %d\n", len);
  // printf("%s\n", word);
}
//..............................................................................
//..............................................................................
int Word_Fill (char word[], Alp letters[])
{
  char c;
  int len = 0;

  while ( (c = getchar() ) && c != EOF )
  {
    word[len] = c;
    len++;
    if (c >= 97 && c <= 122)
    {
      letters[  ((int) c ) - 97].letter = c;
      letters[  ((int) c ) - 97].freq++;
    }
  }
  if (len != 0)
    word[len - 1] = '\0';
  else
    word[len] = '\0';

  return len - 1;
}
//..............................................................................
//..............................................................................
int Compare (const void* Letter_1, const void* Letter_2)
{
  assert (Letter_1);
  assert (Letter_2);

  Alp* First = (Alp*) Letter_1;
  Alp* Second = (Alp*) Letter_2;


  return (Second->freq - First->freq);
}
//..............................................................................
//..............................................................................
Result Bytecoder (Alp letters[])
{
  int num_let = 0, num_bits = 0;
  Result result = { 0, 0 };


  if (letters[0].freq != 0)
  {
    num_let++;
    num_bits += letters[0].freq;
  }

  for (int i = 1; i < 26; i++)
  {

    if (letters[i].freq != 0)
    {
      num_let++;

      for (int k = 1; k <= i; k++)
        letters[i].bytecode = letters[i].bytecode | (1u << k);

      num_bits += (i + 1) * letters[i].freq;

    }
    else
    {
      if (i != 1)
      {
        letters[i - 1].bytecode = letters[i - 1].bytecode | 1u;

        result.num_bits = num_bits - letters[i - 1].freq;
        result.num_let = num_let;

        return result;
      }
      else
      {
        result.num_bits = num_bits;
        result.num_let = num_let;

        return result;
      }
    }
  }
  letters[25].bytecode = letters[25].bytecode | 1u;
  result.num_bits = num_bits - letters[25].freq;
  result.num_let = num_let;

  return result;
}
//..............................................................................
//..............................................................................
void Print_Func (Alp letters[], Result result)
{
  printf("%d %d\n", result.num_let, result.num_bits);

  for (int i = 0; i < result.num_let; i++)
  {
    printf("%c : ", letters[i].letter);
    if (result.num_let == 1)
    {
      printf("%d\n", 0);
      break;
    }
    if (i < result.num_let - 1)
    {
      for (int k = 0; k <= i - 1; k++)
        printf("%d", 1);

      printf("%d", 0);
    }
    else
    {
      for (int k = 0; k <= i - 1; k++)
        printf("%d", 1);
    }
    printf("\n");
  }
}
//..............................................................................
//..............................................................................
void Decoder (char word[], Alp letters[], int len, int num_let)
{
  int counter = 0;
  char c;

  for (int i = 0; i < len; i++)
  {
    c = word[i];

    for (int j = 0; j < num_let; j++)
    {
      if (num_let == 1)
      {
        printf("%d", 0);
        break;
      }
      if (c != letters[j].letter)
        printf("%d", 1);
      else
      {
        if (j == num_let - 1)
          break;
        else
        {
          printf("%d", 0);
          break;
        }
      }
    }
  }
  printf("\n");
}
//..............................................................................
//..............................................................................
