/*
  Feature name : bitfield
  Compilation flags : gcc -W -Wall -Wextra -Werror
  Is it epitech-norm compliant :  Yes
  Source : -
  Explanations : Bitfield let you set the size of any variable, in bit. The variable must be an integer.
  Found by grange_c.
*/

#include <stdio.h>

typedef struct   s_struct
{
  int            i : 1;// i is one bit long, so it can only have 0 or 1 as value.
  int            j : 2;// j is two bit long
  int            k : 3;// k is three bit long
}                t_struct;

typedef struct   __attribute__((packed)) s_struct2
{
  int            i : 1;
  int            j : 2;
  int            k : 3;
}                t_struct2;

int main()
{
   printf("Sizeof t_struct: %lu\n", sizeof(t_struct));
   //1 + 2 + 3 = 6, so the structure is 6 bit length. It will be promoted to a byte length.

   // BUT (There is always a but...)

   //Structure members are padded in memory. That means that the size of a structure is alaways a multiple of the word size, wich is 4 or 8 bits depending of your processor.

   //If you want your structure to not be padded, so it will be 1 byte length, you must use
   // __attribute__ ((packed))
   //like in the second structure.
   printf("Sizeof t_struct2 : %lu\n", sizeof(t_struct2));
   return (0);
}
