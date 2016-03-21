/*
Feature name: Variable-length arrays in C99
Compilation flags : gcc -W -Wall -Wextra -Werror
Is it epitech-norm compliant : Probably yes
Source : https://gcc.gnu.org/onlinedocs/gcc-4.3.2/gcc/Variable-Length.html
Explanations : An array, but with a variable length
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static char     *concat_strings(const char *a, const char *b)
{
  char          s[strlen(a) + strlen(b) + 1];

  strcpy(s, a);
  strcat(s, b);
  return strdup(s);
}

int     main()
{
  char  *s;

  puts(s = concat_strings("Hello ", "World!"));
  free(s);
  return (0);
}
