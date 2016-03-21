/*
  Feature name : Function inheritance in C
  Compilation flags : gcc -W -Wall -Wextra -Werror -fms-extentions
  Is it epitech-norm compliant :  Yes
  Source : http://jonathanpoelen.blogspot.fr/2013/01/structure-et-union-anonyme.html
  Explanations : Anonymous structures that aren't anonymous ! :D Allows you inheritance-like in C, without any functions. 
  Found by grange_c, melis_m
*/

#include <stdio.h>

typedef struct  s_reel
{
  double        r;
}               t_reel;

typedef struct  s_complex
{
  t_reel;
  double        c;
}               t_complex;

int             main()
{
  t_complex     complx;

  complx.r = 5;
  complx.c = 10;
  printf("Complex is equal to : %.f + %.fi\n", complx.r, complx.c);
}
