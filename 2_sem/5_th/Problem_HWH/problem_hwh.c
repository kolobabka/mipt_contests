#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//..............................................................................
typedef struct hash_cell {
  struct hash_cell* next;
  char* word;
  int repeat;

} cell;
//..............................................................................
void Free_Table (cell** table, int len_table);
char* Add_Word (char* string);
void Fill_Table (cell** table, char* string, int len);
int Hash_of_Char (char* string, int len);
int Hash_of_Int (int number);
int pow_mod (unsigned n, unsigned k, unsigned m);
//..............................................................................
int Hash_of_Char (char* string, int len)
{
  int h_c = 0;
  int r = 241;
  int p = 919;
  int sum = 0;

  for (int i = 0; i < len; i++)
  {
    sum += (string[i] * pow_mod (r, len - i, p)) % p;
  }
  sum = sum % p;

  h_c = Hash_of_Int (sum);

  return h_c;
}
//..............................................................................
int Hash_of_Int (int number)
{
  int p = 2909;
  int a = 211;
  int b = 521;
  int m = 2137;

  int h_int = 0;

  h_int = ((a*number + b) % p) % m;

  return h_int;

}
//..............................................................................
int main (int argc, char** argv)
{
  int n_answers = 0;
  int len_text = 0;
  int len_req = 0;
  char* text = NULL;
  char* req = NULL;
  char* req_orig = NULL;
  cell** table = NULL;
  FILE* inp;
  int res = 0;
  int len_table = 2137;
  int flag = 0;
  cell* cur = NULL;
  int* arr = NULL;

  if (argc < 2)
  {
    printf("Usage: <%sfile-to-open\n", argv[0]);
    return -1;
  }

  inp = fopen (argv[1], "r");

  if (inp == NULL)
  {
    perror ("File open error:");
    return -2;
  }

  table = (cell**) calloc (len_table, sizeof (cell*));
  assert (table);

  res = fscanf (inp, "%d", &n_answers);
  assert (res == 1);
  res = fscanf (inp, "%d", &len_text);
  assert (res == 1);

  text = (char*) calloc (len_text + 1, sizeof (char));
  assert (text);

  fscanf(inp, "\n");

  for (int i = 0; i < len_text; i++)
  {
    res = fscanf(inp, "%c", text + i);
    assert (res == 1);
    if (text[i] == ' ')
      text[i] = '\0';
  }

  text[len_text] = '\0';
    fscanf(inp, "\n");

  res = fscanf (inp, "%d", &len_req);
  assert (res == 1);

  req = (char*) calloc (len_req + 1, sizeof (char));
  assert (req);
  req_orig = req;

    fscanf(inp, "\n");

  for (int i = 0; i < len_req; i++)
  {
    res = fscanf(inp, "%c", req + i);
    assert (res == 1);

    if (req[i] == ' ')
      req[i] = '\0';
  }
    
  req[len_req] = '\0';
  //
  //printf("hash = %d\n", Hash_of_Char (req, strlen (req)));
  //
  //printf("%s\n", req);

  for (int i = 0; i < len_table; i++)
  {
    table[i] = (cell*) calloc (1, sizeof (cell));
    assert (table[i]);
  }

  Fill_Table (table, text, len_text);

  arr = (int*) calloc (n_answers, sizeof (int));

  for (int i = 0; i < n_answers; i++)
  {
    cur = table[Hash_of_Char(req, strlen (req))];
    while (cur != NULL)
    {
      if (!cur->word)
      {
        arr[i] = 0;
        break;
      }

      for (int j = 0; j < strlen (req) &&  j < strlen (cur->word); j++)
      {
        if (cur->word[j] != req[j])
        {
          flag = 0;
          break;
        }
        flag++;
      }

      if (flag == strlen (req))
      {
        arr[i] = cur->repeat;
        flag = 0;
        break;
      }

      flag = 0;
      cur = cur->next;
      if (!cur)
      {
        arr[i] = 0;
      }
    }
    req = req + strlen (req) + 1;
    printf("%d ", arr[i]);
  }

  Free_Table (table, len_table);

  free (table);
  free (req_orig);
  free (text);
  fclose (inp);

}
//..............................................................................
int pow_mod (unsigned n, unsigned k, unsigned m)
{
  int mult, prod;
  if (n == 0 || n == 1 || k == 1)
    return n;
  if (k == 0)
    return 1;
  mult = n;
  prod = 1;
  while (k > 0)
  {
    if ((k % 2) == 1)
      prod = (prod * mult) % m;
    mult = (mult * mult) % m;
    k = k / 2;
  }
  return prod;
}
//..............................................................................
void Fill_Table (cell** table, char* string, int len)
{
  int hash = 0;
  int flag = 0;
  cell* cur = NULL;

  for (int i = 0; i < len;)
  {
    hash = Hash_of_Char (string, strlen (string));
    cur = table[hash];

    if (cur->word == NULL)
    {
      cur->word = Add_Word (string);
      cur->repeat++;
    }
    else
    {
      while (1)
      {
        if (!cur->word)
        {
          cur->word = Add_Word (string);
          cur->repeat++;
          break;
        }
        for (int j = 0; j < strlen (string) && j < strlen (cur->word); j++)
        {
          if (cur->word[j] != string[j])
            break;
          flag++;
        }
        if (flag == strlen (string))
        {
          cur->repeat++;
          flag = 0;
          break;
        }
        flag = 0;
        if (cur->next)
        {
          cur = cur->next;
          continue;
        }
        else
        {
          cur->next = (cell*) calloc (1, sizeof (cell));
          assert (cur->next);
          cur = cur->next;

          cur->word = Add_Word (string);
          cur->repeat++;
          break;
        }
      }
    }
    i += strlen (string) + 1;
    string += strlen (string) + 1;
  }
}
//..............................................................................
char* Add_Word (char* string)
{
  char* word = NULL;
  assert (string);

  word = (char*) calloc (strlen (string) + 1, sizeof (char));
  assert (word);

  for (int k = 0; k < strlen (string); k++)
  {
    word[k] = string[k];
  }
  word[strlen (string)] = '\0';

  return word;
}
//..............................................................................
void Free_Table (cell** table, int len_table)
{
  cell* cur = NULL;
  cell* prev = NULL;

  for (int i = 0; i < len_table; i++)
  {
    if (table[i]->next != NULL)
    {
      cur = table[i];
      while (cur->next)
      {
        prev = cur;
        cur = cur->next;
        free (prev->word);
        free (prev);
      }
      free (cur->word);
      free (cur);
    }
    else
    {
      free (table[i]->word);
      free (table[i]);
    }
  }
}
