#include <stdlib.h>
#include <string.h>

char **
buildargv (char *input)
{
  printf("strcmp ");
  static char *arglist[256];
  int numargs = 0;

  while (1)
    {
      while (*input == ' ')
	input++;
      if (*input == 0)
	break;
      arglist [numargs++] = input;
      while (*input != ' ' && *input != 0)
	input++;
      if (*input == 0)
	break;
      *(input++) = 0;
    }
  arglist [numargs] = NULL;
  return arglist;
}


int main()
{
  char **args;
  char input[256];
  int i;

  strcpy(input, " a b");
  args = buildargv(input);

  if (strcmp (args[0], "a"))
   { printf("abort_main "); 		abort (); }
  if (strcmp (args[1], "b"))
   { printf("abort_main "); 		abort (); }
  if (args[2] != NULL)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

