/*
** Feature name : 'for' with macros
** Compilation flags : gcc -W -Wall -Wextra -Werror
** Is it epitech-norm compliant : No
** Source : None
** Explanations : I'm making a FOR macro that is working like the
** for keyword. It's taking three arguments : the first one is
** the initialisation part, the second one is the condition to keep
** the loop going on, and the third one is the incrementation part.
** Found by Benjamin Grange (benjamin.grange@epitech.eu). Based on
** an idea by Antoine Motet (antoine.motet@epitech.eu)
*/

#define MERGE(a,b)  a##b
#define CREATE_LABEL(a) MERGE(__for_, a)
#define UNIQUE_NAME CREATE_LABEL(__LINE__)

#define FOR(init, loop, incr)                                   \
  init;                                                         \
  int UNIQUE_NAME = 0;                                          \
  while ((void)(UNIQUE_NAME && (incr)), UNIQUE_NAME = 1, loop)

/*
** By doing `while (A, B, loop)`, I'm doing what's inside A and B,
** and the result is C. So the while takes the value of 'loop'!
** So I need to set the incrementation inside the loop, but if I
** do so, it will increment before the first loop, and that's not
** what I want: I want to increment at the end of the first loop
** To do so, I'm creating a variable that is set to 0, and I will
** apply the incrementation only when this variable is set to 1.
** I have something like that:
**
**      int i = 0; while ((i == 1) && incr, i = 1, loop)
**
** where incr is the incrementation part of the FOR macro. So when
** i == 0, which is the first time because it takes the value 1 just
** after, I do not apply the incrementation.
** And for all the other times, i == 1 so I will apply the
** incrementation.
**
** The interesting part is that I can't call my variable 'i' like I
** did just above, or you will not be able to use two FOR in the
** same block (multiple declaration of variable `i`...): I need
** to set a unique name to my variable.
** This is done by merging the '__for_' prefix with the line
** number to constitute a unique variable name. (UNIQUE_NAME macro)!
**
** By the way, these methods work fine when we need incrementation,
** decrementation or for linked lists!
**
** With all these elements, we can make the `for` macro :D
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
  FOR(int i = 0, i < argc, i++)
    {
      printf("Argument #%i: %s\n", i, argv[i]);
    }
  return (0);
}
