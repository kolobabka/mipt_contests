#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void turn_str (char* res, int len);
void fill_str(char* str, int len);
int main ()
{
  int len1 = 0, len = 0;
  char* str_f = NULL;
  char* str = NULL;
  char* res = NULL;
  scanf ("%d%*c", &len1);

  str_f = (char*) calloc (len1 + 1, sizeof(char));

  fill_str (str_f, len1);

  scanf ("%d%*c", &len);

  str = (char*) calloc (len + 1, sizeof(char));

  fill_str (str, len);

  res = str;

  while (1)
  {
    res = strstr(res, str_f);
    if (res == NULL)
    {
      break;
    }
    turn_str (res, len1);
    res += len1;
  }
  printf("%s", str);

  free (str_f);
  free (str);
}

void fill_str(char* str, int len)
{
  for (int i = 0; i < len; i++)
  {
    scanf ("%c", &str[i]);
  }
  str[len] = '\0';
}

void turn_str (char* res, int len)
{
  int tmp = 0;
  for (int i = 0; i < len/2; i++)
  {
    tmp = res[i];
    res[i] = res[len - 1 - i];
    res[len - 1 - i] = tmp;
  }
}
