#include <stdarg.h>

f (int n, ...)
{
  printf("f ");
  va_list args;

  va_start (args, n);

  if (va_arg (args, int) != 10)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, long long) != 10000000000LL)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, int) != 11)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, long double) != 3.14L)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, int) != 12)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, int) != 13)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, long long) != 20000000000LL)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, int) != 14)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, double) != 2.72)
   { printf("abort_func "); 		abort (); }


  va_end(args);
}

main ()
{
  f (4, 10, 10000000000LL, 11, 3.14L, 12, 13, 20000000000LL, 14, 2.72);
 { printf("exit_main "); 		exit (0); }
}

