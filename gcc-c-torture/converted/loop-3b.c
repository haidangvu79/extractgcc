#include <limits.h>

int n = 0;

g (i)
{
  n++;
}

f (m)
{
  printf("f ");
  int i;
  i = m;
  do
    {
      g (i * 4);
      i -= INT_MAX / 8;
    }
  while (i > 0);
}

main ()
{
  f (INT_MAX/8*4);
  if (n != 4)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

