#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

//..............................................................................

char *do_replace (char* word, int nword, char* repl, int nrepl, char* str, int nstr);
char *read_word (int* len);
char *strcat_r (char *dest, int dstlen, const char* src, int srclen, int *bufsz);
char *replace(char *str, char const *from, char const *to);

//..............................................................................

int main ()
{
  int nword = 0, nrepl = 0, nstr = 0;
  char *word = NULL;
  char *repl = NULL;
  char *str = NULL;
  char *result = NULL;

  word = read_word (&nword);
  repl = read_word (&nrepl);
  str = read_word (&nstr);

  printf("Replacing in: <%s>\n", word);
  printf("Text to find: <%s>\n", repl);
  printf("Text to replace: <%s>\n", str);

  result = replace (word, repl, str);

  printf("Result is: <%s>\n", result);
}

//..............................................................................

//..............................................................................

char *read_word (int* len)
{
  char* text = NULL;
  int res = 0, i = 0;

  res = scanf ("%d", len);
  assert (res == 1);

  text = (char*) calloc (*len + 1, sizeof (char));
  assert (text != NULL);

  scanf("%*c");

  for (i; i < *len; ++i)
  {
    res = scanf ("%c", text + i);
    assert (res);
  }

  return text;
}

//..............................................................................
char *strcat_r (char *dest, int dstlen, const char* src, int srclen, int *bufsz)
{
  int bsz = *bufsz;
  int len = dstlen + srclen + 1;

  while (len > bsz)
  {
    bsz *= 2;
    if (bsz >= len)
    {
      dest = realloc (dest, bsz);
      assert (dest);
    }
  }
  strncat (dest, src, srclen);
  *bufsz = bsz;
  return dest;
}

char *do_replace (char* word, int nword, char* repl, int nrepl, char* str, int nstr)
{

  char *buf = NULL;
  char *substr;
  int buflen = 0, bufstrlen = 0;
  buflen = nword;

  buf = (char*) calloc (buflen, sizeof (char));

  for (; ;)
  {
    substr = strstr (word, repl);
    if (substr == NULL)
      break;

    buf = strcat_r (buf, bufstrlen, word, substr - word, &buflen);
    bufstrlen += (substr - word);

    buf = strcat_r (buf, bufstrlen, str, nstr, &buflen);
    bufstrlen += nstr;

    substr += nrepl;
    word = substr;
  }
  nword = strlen (word);
  if (nword > 0)
    buf = strcat_r (buf, bufstrlen, word, nword, &buflen);

  return buf;
}

char *replace(char *str, char const *from, char const *to)
{
  return (do_replace (str, strlen (str), from, strlen (from), to, strlen (to)));
}
