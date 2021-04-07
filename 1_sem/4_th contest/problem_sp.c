#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* read_word (int* len);
char *strcat_r (char *dest, const char* src, int *bufsz);
char *replace(char *str, char const *from, char const *to);

int main ()
{
  int nword, nrepl, nstr;

  char* word = NULL;
  char* repl = NULL;
  char* str = NULL;

  word = read_word (&nword);
  printf("PIZDA\n");
  repl = read_word (&nrepl);
  str = read_word (&nstr);

  printf("Replacing in: <%s>\n", word);
  printf("Text to find: <%s>\n", repl);
  printf("Text to replace: <%s>\n", str);
}

char *strcat_r (char *dest, const char* src, int *bufsz)
{
  int bsz = *bufsz;
  int len = strlen (dest) + strlen (src) + 3;

  while (len > bsz)
  {
    bsz *= 2;
    if (bsz >= len)
    {
      dest = realloc (dest, bsz);
      assert (dest);
    }
  }
  strcat (dest, src);
  *bufsz = bsz;
  return dest;
}

char* read_word (int* len)
{
  char* text = NULL;
  int res = 0, i = 0;

  res = scanf ("%d", len);
  assert (res == 1);

  text = (char*) calloc (*len+1, sizeof (char));
  assert (text != NULL);

  scanf ("%*c");

  for (i = 0; i < *len; i++)
  {
    res = scanf ("%c", text + i);
    assert (res);
  }
  printf("%d\n", i);
  return text;
}

char *replace(char *str, char const *from, char const *to)
{

}


















































  /*str = (char*) malloc (1024);
  from = (char*) malloc (1024);
  to = (char*) malloc (1024);

  assert (res);
  strcpy (str, "Nrterminterminateaterminatetea yIDsS Xrtteterminaterminateermterminateinatej zFnmteterminaterminate j Eo cJZ XQ vPq ZBtermiterminatterminateeterminatentermiterminatenateateV");
  strcpy (from, "terminate");
  strcpy (to, "term");

  res = strstr (str, from);



  str = replace (str, from, to);

  //printf("\n%s\n", str);
  free (str);
  free (from);
  free (to);*/







/*char *replace(char *str, char const *from, char const *to)
{
  int j = 0, len_to = 0, len_from = 0, i = 0;
  char* new = NULL;
  char* res = NULL;
  res = str;
  len_to = strlen (to);
  len_from = strlen (from);
  new = (char*) malloc (1000000);
  while (1)
  {
    res = strstr(res, from);
    if (res == NULL)
      break;

    for (i; i < strlen (str); i++ )
    {
      if (res == &(str[i]) )
      {
        for (int k = 0; k < len_to; k++)
        {
          new[j] = to[k];
          j++;
        }
        i += len_from;
        res += len_from / 2;
        break;
      }
      else
      {
        new[j] = str[i];
        j++;
      }
    }
  res += len_from / 2;
  }
  while (i < strlen (str))
  {
    new[j] = str[i];
    j++;
    i++;
  }
  str = new;

  return str;
}*/
