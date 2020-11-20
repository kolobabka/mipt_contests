#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *str, char const *from, char const *to);
int main ()
{
  char *str = NULL;
  char *from = NULL;
  char *to = NULL;
  char *res = NULL;

  str = (char*) malloc (1024);
  from = (char*) malloc (1024);
  to = (char*) malloc (1024);

  strcpy (str, "Nrterminterminateaterminatetea yIDsS Xrtteterminaterminateermterminateinatej zFnmteterminaterminate j Eo cJZ XQ vPq ZBtermiterminatterminateeterminatentermiterminatenateateV");
  strcpy (from, "terminate");
  strcpy (to, "term");

  res = strstr (str, from);



  str = replace (str, from, to);

  printf("\n%s\n", str);
  free (str);
  free (from);
  free (to);


}

char *replace(char *str, char const *from, char const *to)
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
}
