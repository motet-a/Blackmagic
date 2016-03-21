/*
  Feature name : exit-like function.
  Compilation flags : gcc -W -Wall -Wextra -Werror
  Is it epitech-norm compliant :  Yes
  Source : https://gcc.gnu.org/onlinedocs/gcc/Return-Address.html
  Explanations : see comments
  Found by grange_c
*/

#include <stdio.h>

//I'm using a global here, but you can keep a reference on exit_adr to avoid this global.
void  *exit_adr;

void  my_exit()
{
  void  (*exit_func)();

  exit_func = exit_adr;
  exit_func(); //I'm using going at the end of the main, so the program is exiting.
}

void  prepare_exit()
{
  void  *tmp;

  tmp = __builtin_return_address(1); //This function returns the return address of the current function, or of one of its callers.
  //Here, i'm asking the address of the main()'s return. If the parameter is 0, it will be the address of prepare_exit()'s return.
  exit_adr = __builtin_extract_return_addr(tmp);
}

void  print_and_exit()
{
  printf("I'm leaving...\n");
  my_exit();
}

int main()
{
  prepare_exit();
  print_and_exit();
  printf("This string souldn't be seen, because you have already exited this program !\n");
}
