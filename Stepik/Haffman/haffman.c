#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
typedef struct alphabet {

  char letter;
  int freq;
  int bytecode[32];
  int bytecode_len;
  struct alphabet* next;
  struct alphabet* prev;
  struct alphabet* left;
  struct alphabet* right;

} Alp;
//..............................................................................
//..............................................................................
typedef struct result {

  int num_let;
  int num_bits;

  struct alphabet* top;

} Result;
//..............................................................................
//..............................................................................
int Word_Fill (char word[], Alp* letters[]);
Result Bytecoder (Alp* letters[]);
int Compare (const void* Letter_1, const void* Letter_2);
void Create_List (Alp* letters[], int num_let);
Alp* Tree_Maker (Alp* node);
Alp* Sort_List (Alp* node);
void Free_Tree (Alp* node);
void Coder (Alp* node, Result* result);
void Print (Result* result, Alp* letters[]);
void Print_Code (Result* result, Alp* letters[], char word[], int len);
//..............................................................................
//..............................................................................
int height = 0;
int code[26] = {0};
//..............................................................................
//..............................................................................
int main ()
{
  int len = 0;
  char* word = (char*) calloc (200001, sizeof (char));
  Result result = { 0, 0, NULL };
  Alp* letters[26] = {};

  for (int i = 0; i < 26; i++)
  {
    letters[i] = (Alp*) calloc (1, sizeof (Alp));
    assert (letters[i]);
  }
  len = Word_Fill (word, letters);

  qsort (letters, 26, sizeof (Alp*), Compare);

  result = Bytecoder (letters);
  qsort (letters, 26, sizeof (Alp*), Compare);

  Print (&result, letters);
  Print_Code (&result, letters, word, len);

  Free_Tree (result.top);

  for (int i = result.num_let; i < 26; i++)
    free (letters[i]);

  free (word);
  return 0;
}
//..............................................................................
//..............................................................................
int Word_Fill (char word[], Alp* letters[])
{
  char c;
  int len = 0;

  while ( 1 )
  {
    c = getchar();
    if (c >= 97 && c <= 122)
    {
      word[len] = c;
      len++;
      letters[  ((int) c ) - 97]->letter = c;
      letters[  ((int) c ) - 97]->freq++;
    }
    else
      break;
  }
  word[len] = '\0';

  return len;
}
//..............................................................................
//..............................................................................
int Compare (const void* Letter_1, const void* Letter_2)
{
  assert (Letter_1);
  assert (Letter_2);

  Alp** First = (Alp**) Letter_1;
  Alp** Second = (Alp**) Letter_2;

  if (First[0]->freq == 0)
    return 1;

  if (Second[0]->freq == 0)
    return -1;

  return (First[0]->freq - Second[0]->freq);
}
//..............................................................................
//..............................................................................
Result Bytecoder (Alp* letters[])
{
  int num_let = 0;
  Result result = {0, 0, NULL};
  Alp* node = NULL;

  while (num_let < 26 && letters[num_let]->freq != 0)
    num_let++;

  result.num_let = num_let;
  result.top = letters[0];

  if (num_let == 1)
  {
    result.num_bits = letters[0]->freq;
    letters[0]->bytecode_len = 1;
    return result;
  }

  Create_List (letters, num_let);
  node = letters[0];

  node = Tree_Maker (node);
  result.top = node;

  Coder (result.top, &result);

  return result;
}
//..............................................................................
//..............................................................................
void Create_List (Alp* letters[], int num_let)
{

  for (int i = 0; i < num_let - 1; i++)
  {
    letters[i]->next = letters[i + 1];
    letters[i + 1]->prev = letters[i];
  }

  letters[num_let - 1]->prev = letters[num_let - 2];
}
//..............................................................................
//..............................................................................
Alp* Tree_Maker (Alp* node)
{
  assert (node);
  Alp* start = NULL;

  start = node;

  while (node)
    node = node->next;

  node = start;

  while (node->next)
  {
    Alp* tmp = (Alp*) calloc (1, sizeof (Alp));

    tmp->freq  = node->freq + node->next->freq;
    tmp->left  = node;
    tmp->right = node->next;
    tmp->next  = node->next->next;
    if (node->next->next)
      node->next->next->prev = tmp;
    tmp->prev  = NULL;

    node = tmp;
    node = Sort_List (tmp);

  }
  return node;

}
//..............................................................................
//..............................................................................
Alp* Sort_List (Alp* node)
{
  assert (node); //100% it falls :)
  Alp* start = NULL;
  Alp* restart = NULL;

  if (!node->next)
    return node;

  if (node->freq > node->next->freq)
    restart = node->next;
  else
  {
    restart = node;
    return node;
  }
  start = node;
  node = node->next;

  while (node) // or it :)
  {
    if (start->freq > node->freq)
    {
      node->prev = start->prev;
      start->prev = node;
      if (!node->next)
        break;
      node = node->next;
    }
    else
    {
      node->prev = start;
      start->next = node;
      start->prev->next = start;
      return restart;
    }
  }
  node->next = start;
  start->prev = node;
  start->next = NULL;
  return restart;
}
//..............................................................................
//..............................................................................
void Free_Tree (Alp* node)
{
  if (node->left)
    Free_Tree (node->left);

  if (node->right)
    Free_Tree (node->right);

  free (node);
}
//..............................................................................
//..............................................................................
void Coder (Alp* node, Result* result)
{

  if (node->left)
  {
    code[height] = 1;
    height++;
    Coder (node->left, result);
    height--;
  }

  if (node->right)
  {
    code[height] = 0;
    height++;
    Coder (node->right, result);
    height--;
  }

  if (node->letter >= 97 && node->letter <= 122)
  {
    node->bytecode_len = height;

    result->num_bits += height * node->freq;

    for (int i = 0; i < height; i++)
      node->bytecode[i] = code[i];
  }
}
//..............................................................................
//..............................................................................
void Print (Result* result, Alp* letters[])
{
  printf("%d %d\n", result->num_let, result->num_bits);

  for (int i = result->num_let - 1; i >= 0; i--)
  {
    printf("%c: ", letters[i]->letter);
    for (int j = 0; j < letters[i]->bytecode_len; j++)
      printf("%d", letters[i]->bytecode[j]);
    printf("\n");
  }
}
//..............................................................................
//..............................................................................
void Print_Code (Result* result, Alp* letters[], char word[], int len)
{

  for (int i = 0; i < len; i++)
    for (int j = 0; j < result->num_let; j++)
      if (word[i] == letters[j]->letter)
        for (int k = 0; k < letters[j]->bytecode_len; k++)
          printf("%d", letters[j]->bytecode[k]);

  printf("\n");
}
