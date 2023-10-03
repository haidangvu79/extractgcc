/* Verify that we do not lose side effects on a MOD expression.  */

#include <stdlib.h>
#include <stdio.h>

int
foo (int a)
{
  printf("foo ");
  int x = 0 % a++;
  return a;
}

main()
{
  if (foo (9) != 10)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

