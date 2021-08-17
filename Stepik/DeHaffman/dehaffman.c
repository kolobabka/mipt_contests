#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//..............................................................................
//..............................................................................
typedef struct alphabet {

  char letter;
  int bytecode[216];
  int bytecode_len;
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
void Decoder (Alp* letters[], Result* result, char word[], int len);
int Letters_Fill (Alp* letters[], Result* result, char word[]);
void Tree_Maker (Alp* letters[], Result* result);
void Free_Tree (Alp* node);
//..............................................................................
//..............................................................................
int main ()
{
  Result result = {0, 0, NULL};
  int check = 0, len = 0;
  Alp* letters[27] = {0};
  char word[10010] = {0};

  for (int i = 0; i < 26; i++)
  {
    letters[i] = (Alp*) calloc (1, sizeof (Alp));
    assert (letters[i]);
  }

  check = scanf ("%d%d", &(result.num_let), &(result.num_bits));
  assert (check == 2);

  len = Letters_Fill (letters, &result, word);

  Tree_Maker (letters, &result);
  Decoder (letters, &result, word, len);

  Free_Tree (result.top);
  
  for (int i = result.num_let; i < 26; i++)
    free (letters[i]);

}
//..............................................................................
//..............................................................................
int Letters_Fill (Alp* letters[], Result* result, char word[])
{
  int check = 0, len = 0;
  int let;
  let = getchar ();
  for (int i = 0; i < result->num_let; i++)
  {
    assert (let == '\n');
    let = getchar ();
    letters[i]->letter = let;

    //printf("let = %c\n", let);

    let = getchar ();
    //printf("let = %c\n", let);
    assert (let == ':');

    let = getchar ();
    //printf("let = %c\n", let);
    assert (let == ' ');

    let = getchar ();
    //printf("let = %c\n", let);

    while ( let == 48 || let == 49 )
    {
      letters[i]->bytecode[letters[i]->bytecode_len] = (int) let - 48;
      letters[i]->bytecode_len++;
      let = getchar ();
      //printf("let = %c\n", let);
    }
    if (let == '\n')
      continue;
  }
  let = getchar ();

  while (let == 48 || let == 49)
  {
    word[len] = let;
    let = getchar ();
    len++;
  }
  word[len] = '\0';

  return len;

}
//..............................................................................
//..............................................................................
void Tree_Maker (Alp* letters[], Result* result)
{
  Alp* top = NULL;
  Alp* node = NULL;

  top = (Alp*) calloc (1, sizeof (Alp));
  assert (top);

  node = top;

  for (int i = 0; i < result->num_let; i++)
  {
    for (int j = 0; j < letters[i]->bytecode_len - 1; j++)
    {
      if (letters[i]->bytecode[j] == 0)
      {
        assert (node);
        if (node->left)
          node = node->left;
        else
        {
          node->left = (Alp*) calloc (1, sizeof (Alp));
          node = node->left;
        }
      }
      else
      {
        assert (node);
        if (node->right)
          node = node->right;
        else
        {
          node->right = (Alp*) calloc (1, sizeof (Alp));
          node = node->right;
        }
      }
    }

    assert (node);
    if (letters[i]->bytecode[letters[i]->bytecode_len - 1] == 0)
      node->left = letters[i];
    else
      node->right = letters[i];

    node = top;
  }
  result->top = top;

}
//..............................................................................
//..............................................................................
void Decoder (Alp* letters[], Result* result, char word[], int len)
{

  Alp* node = result->top;

  for (int i = 0; i < len; i++)
  {

    // /printf("word[%d] = %c\n", i, word[i]);

    if (word[i] == '0' )
      node = node->left;
    if (word[i] == '1')
      node = node->right;

    if (node && node->left == NULL && node->right == NULL)
    {
      printf("%c", node->letter);
      node = result->top;

    }
  }
  printf("\n");
}
//..............................................................................
//..............................................................................
void Free_Tree (Alp* node)
{
  if (node == NULL)
    return;

  if (node->left)
    Free_Tree (node->left);

  if (node->right)
    Free_Tree (node->right);

  free (node);
}
//..............................................................................
//..............................................................................
