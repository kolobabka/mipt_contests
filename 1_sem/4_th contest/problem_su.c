#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
//..........................................................

char * strstrci(char const * needle, char const * haystack);

//..........................................................

int main ()
{
  char const *needle = "Ab", *src = "abracadaBra";
  char* pos = NULL;

  pos = strstrci (needle, src);
  pos = strstrci (needle, pos + 2);
  pos = strstrci (needle, pos + 2);
  //assert (pos != NULL);

  printf("%s\n", pos);

}

//..........................................................

char * strstrci(char const * needle, char const * haystack)
{
  int count_needle = 0;
  for (int count_str = 0; count_str < strlen (haystack); count_str++)
  {
    while (1)
    {
      if (tolower (needle[count_needle]) == tolower (haystack[count_str]))
      {
        count_needle++;
        if (count_needle == strlen (needle))
          return haystack + count_str + 1 - count_needle;
        break;
      }
      count_needle = 0;
      break;
    }
  }
  return NULL;
}
