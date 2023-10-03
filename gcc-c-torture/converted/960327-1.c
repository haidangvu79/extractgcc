#include <stdio.h>
g ()
{
  return '\n';
}

f ()
{
  printf("f ");
  char s[] = "abcedfg012345";
  char *sp = s + 12;

  switch (g ())
    {
  printf("f ");
      case '\n':
        break;
    }

  while (*--sp == '0')
    ;
  sprintf (sp + 1, "X");

  if (s[12] != 'X')
   { printf("abort_func "); 		abort (); }

}

main ()
{
  f ();
 { printf("exit_main "); 		exit (0); }
}

