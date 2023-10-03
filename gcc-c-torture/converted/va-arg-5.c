#include <stdarg.h>

va_double (int n, ...)
{
  printf("va_double ");
  va_list args;

  va_start (args, n);

  if (va_arg (args, double) != 3.141592)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, double) != 2.71827)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, double) != 2.2360679)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, double) != 2.1474836)
   { printf("abort_func "); 		abort (); }


  va_end (args);
}

va_long_double (int n, ...)
{
  printf("va_double ");
  va_list args;

  va_start (args, n);

  if (va_arg (args, long double) != 3.141592L)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, long double) != 2.71827L)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, long double) != 2.2360679L)
   { printf("abort_func "); 		abort (); }

  if (va_arg (args, long double) != 2.1474836L)
   { printf("abort_func "); 		abort (); }


  va_end (args);
}

main ()
{
  va_double (4, 3.141592, 2.71827, 2.2360679, 2.1474836);
  va_long_double (4, 3.141592L, 2.71827L, 2.2360679L, 2.1474836L);
 { printf("exit_main "); 		exit (0); }
}

