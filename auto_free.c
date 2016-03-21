/*
Feature name : auto_free
Compilation flags : gcc -fplan9-extensions -Wall -Werror
Is it epitech-norm compliant :  Yes (just remove the printf :D)
Source : https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html#Common-Variable-Attributes
Explanations : gives cleanup attribute to variable. this attribute takes a function as parameter which \
will be called as the varaible gets out of its scope
Found by Wats0ns/maire_q
*/

#include <stdlib.h>

void	free_me(char **to_free)
{
  printf("content to free: %s\n", *to_free);
  free(*to_free);
  printf("%s\n", "I'm free !");
}

int	main()
{
  char 	__attribute__ ((cleanup(free_me))) *to_free; //<- Everythin start here...

  to_free = malloc(sizeof(char) * 129);
  to_free[0] = 'a';//<- Some randomo content to prove it is called
  to_free[2] = '\0';
  printf("%s\n", "returning from main...");
  return(0);
}
