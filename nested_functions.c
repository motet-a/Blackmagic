/*
  Feature name : nested functions
  Compilation flags : gcc
  Is it epitech-norm compliant :  Yes
  Source : https://gcc.gnu.org/onlinedocs/gcc/Nested-Functions.html#Nested-Functions
  Explanations : Nested functions are functions defined inside another function.
  Nested functions can access all variable of the containing function that are visible at the point of its definition.
  Found by maire_q, grange_c
*/

#include <stdio.h>

int main()
{
  void printme(char *str)
  {
    puts(str);
  }

  printme("This string");
  printme("Is print");
  printme("From a");
  printme("Nested function !");
}
