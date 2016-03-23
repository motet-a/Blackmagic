/*
  Feature name : bitfield
  Compilation flags : gcc -W -Wall -Wextra -Werror
  Is it epitech-norm compliant :  Yes
  Source : -
  Explanations : Bitfields let you set the size of any variable, in bits. The variable must be an integer.
  Found by grange_c.
*/

#include <stdio.h>

typedef struct   s_struct
{
  int            i : 1; // i is one bit long, so it can only take the value 0 or the value 1.
  int            j : 2; // j is two bits long
  int            k : 3; // k is three bits long
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
   // 1 + 2 + 3 = 6, so the structure is 6 bit long. It will be promoted to a byte length.

   // BUT (There is always a but...)

   // Structure members are padded in memory. That means that the size of a structure is always a multiple of the word size, which is 4 or 8 bits depending on your processor.

   // If you don't want your structure to be padded, so it can be 1 byte long, you must use :
   // __attribute__ ((packed))
   // like in the second structure.
   printf("Sizeof t_struct2 : %lu\n", sizeof(t_struct2));
   return (0);
}
