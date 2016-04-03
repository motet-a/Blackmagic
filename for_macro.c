/*
** Feature name : 'for' with macros
** Compilation flags : gcc -W -Wall -Wextra -Werror
** Is it epitech-norm compliant : No
** Source : None
** Explanations : I'm making a FOR macro that is working like the for keyword. It's taking three arguments : the first one is
** the initialisation part, the second one is the condition to keep the loop going on, and the third one is the incrementation part.
** Found by Benjamin Grange (benjamin.grange@epitech.eu). Based on an idea by Antoine Motet (antoine.motet@epitech.eu)
*/

#define MERGE(a,b)  a##b
#define CREATE_LABEL(a) MERGE(__for_, a)
#define UNIQUE_NAME CREATE_LABEL(__LINE__)

#define FOR(init, loop, incr) init; int UNIQUE_NAME = 0; while ((void)(UNIQUE_NAME && (incr)), UNIQUE_NAME = 1, loop)

//By doing while (A, B, loop) , i'm doing what's inside A and B, and the result is C. So the while takes the value of 'loop' !
//So i need to set the incrementation inside the loop, but if i do so, it will increment before the first loop,
//and that's not what i want : i want to increment at the end of the first loop
//To do so, i'm creating a variable that is set to 0, and i will apply the incrementation only when this variable is set to 1.
//I have something like that :
//int i = 0; while ((i == 1) && incr, i = 1, loop)

//Where incr is the incrementation part of the FOR macro. So when i == 0, which is the first time because it takes
//the value 1 just after, i do not apply the incrementation.
//And for all the other times, i == 1 so i will apply the incrementation.

//The interesting part is that i can't call my variable 'i' like i did just above, or you will not be able to use 2 FOR
//in the same bloc (multiple declaration of variable i ...) : i need to set a unique name to my variable.
//This is done by mergine the '__for_' prefix with the line number to constitute a unique variable name. (UNIQUE_NAME macro) !

//By the way, this methods works fine when we need incrementation, decrementation or for linked lists !

//With all these elements, we can make the for macro :D

#include <stdio.h>

int main(int argc, char *argv[])
{
  FOR(int i = 0, i < argc, i++)
    {
      printf("Argument nb°%i: %s\n", i, argv[i]);
    }
  return (0);
}
