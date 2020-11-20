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
  int bufsz = 1;
  char* dest = NULL;
  const char src[8] = ", world!";

  dest = (char*) calloc (6, sizeof (char));


  //dest = "Hello";
  strcpy (dest, "Hello");
  //strcat (dest, src);

  //dest = (char*) realloc (dest, 100);

  strcat_r (dest, src, &bufsz);

  printf ("%s\n", dest);
  free (dest);

}

char *strcat_r(char *dest, const char *src, int *bufsz)
{
  int bfz = *bufsz, len1 = 0, len2 = 0, len_res = 0;
  while (dest[len1] != '\0')
  {
    len1 ++;
  }

  while (src[len2] != '\0')
  {
    len2 ++;
  }
  len_res = len1 + len2;

  if (bfz < len_res)
  {
    dest = (char*) realloc (dest, len_res );
  }
  strcat (dest, src);

  *bufsz = bfz;
  return dest;
}
