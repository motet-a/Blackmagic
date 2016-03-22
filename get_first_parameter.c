/*
  Feature name : get the first parameter of a function by knowing only it's type.
  Compilation flags : gcc -W -Wall -Wextra -Werror
  Is it epitech-norm compliant :  Yes
  Source : https://gcc.gnu.org/onlinedocs/gcc/Return-Address.html
  Explanations : Get the function frame address via a GCC builtin, and then navigate through the stack to find the first argument.
  Found by grange_c (benjamin.grange@epitech.eu)
*/

#include <stdio.h>

// This version returns the size of TYPE as it is in the stack. Eg : sizeof(short) == 2 but __rounded__sizeof(short) == 4
#define __rounded__sizeof(TYPE) ((sizeof(TYPE) + (sizeof(int) - 1)) & ~(sizeof(int) - 1))

// And here is the beast...
// Please note that this may NOT be portable and is only guarantee to works on {EPITECH.} computers. 
#define first(TYPE) (*(TYPE *)(__builtin_frame_address(0) - 4 * sizeof(unsigned) - __rounded__sizeof(TYPE)))

void  three_args(float a, float b, float c)
{
  float i;

  (void)b; // b and c are here only to prove that this works with multiple-arguments functions.
  (void)c;
  i = first(float); //Please note that this does NOT works with variable arguments functions. (WIP ...)
  printf("Test with three arguments : [%f : %f]\n", a, i);
}

int main()
{
  three_args(7945.345678, 2, 5);
}
