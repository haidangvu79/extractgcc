#include <stdarg.h>

void fdouble (double one, ...)
{
  double value;
  va_list ap;

  va_start (ap, one);
  value = va_arg (ap, double);
  va_end (ap);

  if (one != 1.0 || value != 2.0)
   { printf("abort_func "); 		abort (); }

}

int main ()
{
  fdouble (1.0, 2.0);
 { printf("exit_main "); 		exit (0); }
}

