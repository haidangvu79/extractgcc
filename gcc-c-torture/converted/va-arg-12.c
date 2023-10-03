#include <stdarg.h>

/*typedef unsigned long L;*/
typedef double L;
void f (L p0, L p1, L p2, L p3, L p4, L p5, L p6, L p7, L p8, ...)
{
  printf("f ");
  va_list select;

  va_start (select, p8);

  if (va_arg (select, L) != 10.)
   { printf("abort_func "); 		abort (); }

  if (va_arg (select, L) != 11.)
   { printf("abort_func "); 		abort (); }

  if (va_arg (select, L) != 0.)
   { printf("abort_func "); 		abort (); }


  va_end (select);
}

int main ()
{
  f (1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 0.);
 { printf("exit_main "); 		exit (0); }
}

