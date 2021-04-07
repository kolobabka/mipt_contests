#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

char *strcat_r(char *dest, const char *src, int *bufsz);

/*int main(void)
{
char *p;
p = (char *) malloc(17);
if(!p) {
printf("Allocation error.");
exit (1);
}
strcpy(p, "This is 16 chars");
p = (char *) realloc (p,18);
if(!p) {
printf("Allocation error.");
exit (1);
}
strcat (p, ".");
printf("%s\n", p);
free(p);
return 0;
}*/

int main ()
{
  char* buf =  malloc (20);
  strcpy(buf, "Hello");
  char* res;
  int bufsz = 20;
  printf("\n\n\nTESTTSTSTSTS\n\n\n");

  printf("strlen Hello = %d\n", strlen (buf));

  res = strcat_r (buf, ", world", &bufsz);
  printf("%s\n", res);

  printf("\n\n\nTESTTSTSTSTS\n\n\n");

  printf("strlen Hello = %d\n", strlen (buf));


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



/*char *strcat_r(char *dest, const char *src, int *bufsz)
{
  int bfz = *bufsz, len1 = 0, len2 = 0, len_res = 0;
  char* new = NULL;
  while (dest[len1] != '\0')
  {
    len1 ++;
  }

  while (src[len2] != '\0')
  {
    len2 ++;
  }
  len_res = len1 + len2 + 1;

  while (len_res > bfz)
  {
    bfz *= 2;
    if (bfz >= len_res)
    {
      dest = (char*) realloc (dest, len_res );
    }
    strcat (dest, src);
  }

  *bufsz = bfz;
  return dest;
}*/
