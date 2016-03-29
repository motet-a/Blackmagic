/*
  Feature name: pseudo static variables
  Compilation flags: gcc -W -Wall -Wextra -Werror
  Is it epitech-norm compliant: Yes
  Source: Myself
  Explanations: Static and global variables are forbidden, but
  we can write funny things without.
  Valgrind can print a lot of "Conditional jumps on unitialised
  value(s)" with this. This is normal, because this program "walks"
  across the stack looking for a given magic string. And the stack
  is full of unitialised values.
  Warning: This program is not guaranteed to work on non-x86
  platforms.
  Found by motet_a - Antoine Motet <antoine.motet@epitech.eu>
*/

#include <stdio.h>

/*
** This one is just needed for memcpy()
*/
#include <string.h>

/*
** A random string. Longer is safer, but longer is slower.
*/
#define MAGIC_STRING_LENGTH 16
#define MAGIC_STRING_0 "\xa8\x74\x91\x64\xab\x80\x30\x68"
#define MAGIC_STRING_1 "\x55\x66\x1d\xf9\x28\x71\x92\xca"
#define MAGIC_STRING MAGIC_STRING_0 MAGIC_STRING_1

typedef struct  s_statics
{
  char          magic_string[MAGIC_STRING_LENGTH];
  const char    *pseudo_static_variable;
}               t_statics;

static int      is_magic_string(const char *s)
{
  int           i;

  i = -1;
  while (++i < MAGIC_STRING_LENGTH)
    {
      if (s[i] != MAGIC_STRING[i])
        return (0);
    }
  return (1);
}

static void     init_statics(t_statics *statics)
{
  memcpy(statics->magic_string, MAGIC_STRING, MAGIC_STRING_LENGTH);
}

/*
** Returns a pointer to the instance of the `t_static` structure
** in the main() function
*/
static void     *get_statics(void)
{
  char          c;
  char          *stack_pointer;

  stack_pointer = &c;
  while (!is_magic_string(stack_pointer))
    stack_pointer++;
  printf("statics found at %p\n", stack_pointer);
  return (stack_pointer);
}

static void     another_function(void)
{
  t_statics     *p;

  p = (t_statics *)get_statics();
  printf("%s\n", p->pseudo_static_variable);
}

int             main()
{
  t_statics     statics;

  init_statics(&statics);
  statics.pseudo_static_variable = "It works!";
  printf("statics is at %p\n", &statics);
  another_function();
  return (0);
}
