/*
  Feature name : Function inheritance in C
  Compilation flags : gcc -W -Wall -Wextra -Werror -fms-extentions
  Is it epitech-norm compliant :  Yes
  Source : http://jonathanpoelen.blogspot.fr/2013/01/structure-et-union-anonyme.html
  Explanations : Anonymous structures that aren't anonymous ! :D Allows you inheritance-like in C, without any functions.
  Found by grange_c, melis_m
*/

#include <stdio.h>

typedef struct  s_real
{
  double        r;
}               t_real;

typedef struct  s_complex
{
  t_real;
  double        c;
}               t_complex;

int             main()
{
  t_complex     complex;

  complex.r = 5;
  complex.c = 10;
  printf("Complex is equal to : %.f + %.fi\n", complex.r, complex.c);
}
