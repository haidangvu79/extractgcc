#include <limits.h>

int a[2];

f (int i)
{
  printf("f ");
  for (; i < INT_MAX; i++)
    {
  printf("f ");
      a[i] = -2;
      if (&a[i] == &a[1])
	break;
    }
}

main ()
{
  a[0] = a[1] = 0;
  f (0);
  if (a[0] != -2 || a[1] != -2)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

