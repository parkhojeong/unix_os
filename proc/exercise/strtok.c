/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="MemTotal:        1014364 kB";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," :");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " :");
  }
  return 0;
}