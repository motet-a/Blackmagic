/*
Feature name : auto_free
Compilation flags : gcc -W -Wall -Wextra -Werror
Is it epitech-norm compliant :  Yes (just remove the printf :D)
Source : https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html#Common-Variable-Attributes
Explanations : Gives cleanup attribute to variable. This attribute takes a function as parameter which
  will be called when the variable gets out of its scope
Found by Wats0ns/maire_q
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	free_me(char **to_free)
{
  printf("Content to free: %s\n", *to_free);
  free(*to_free);
  printf("%s\n", "I'm free !");
}

int	main()
{
  char 	__attribute__ ((cleanup(free_me))) *to_free; //<- Everything starts here...
  //You may add a macro to make an easier way to set cleanup
  //It works a bit like alloca, excepts what it doesn't allocate on the stack. Of course, you cannot return a cleanup pointer.

  to_free = strdup("Hello World !");
  printf("%s\n", "Returning from main...");
  return(0);
}
