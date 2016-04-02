/*
  Feature name: pseudo static variables
  Compilation flags: gcc -W -Wall -Wextra -Werror
  Is it epitech-norm compliant: Yes
  Source: Myself
  Explanations: Static and global variables are forbidden, but
  we can write funny things without.
  Valgrind can print a lot of "Conditional jumps on unitialised
  value(s)" with this. This is normal, because this program "walks"
  across the stack looking for a magic number. And the stack is
  full of unitialised values.
  Warning: This program is not guaranteed to work on non-x86
  platforms.
  Found by motet_a - Antoine Motet <antoine.motet@epitech.eu>
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define STATIC(variable)        (get_statics()->variable)

/*
** A random number.
** You can use anything here, since it looks random and is
** 8 bytes long to fit in a uint64_t.
*/
#define MAGIC_NUMBER    (0x8bc2df231f11ecc6)

typedef struct          s_statics
{
  uint64_t              magic_number;
  char                  *name;
}                       t_statics;

static void             init_statics(t_statics *statics)
{
  statics->magic_number = MAGIC_NUMBER;
}

/*
** Returns a pointer to the instance of the `t_static` structure
** in the main() function
*/
static t_statics        *get_statics(void)
{
  uint64_t              variable_on_the_stack;
  uint64_t              *stack_pointer;

  stack_pointer = &variable_on_the_stack;
  while (*stack_pointer != MAGIC_NUMBER)
    stack_pointer++;
  return ((t_statics *)stack_pointer);
}

static char     *read_string(size_t length)
{
  char          *string;

  string = malloc(length + 1);
  if (!fgets(string, length, stdin))
    string[0] = '\0';
  if (string[0] && string[strlen(string) - 1] == '\n')
    string[strlen(string) - 1] = '\0';
  return (string);
}

static void     read_name()
{
  printf("What's your name?\n");
  STATIC(name) = read_string(20);
}

static void     print_name(void)
{
  if (!STATIC(name)[0])
    printf("Please tell me your name.\n");
  else
    printf("Hello %s!\n", STATIC(name));
}

int             main()
{
  t_statics     statics;

  init_statics(&statics);
  read_name();
  print_name();
  free(STATIC(name));
  return (0);
}
