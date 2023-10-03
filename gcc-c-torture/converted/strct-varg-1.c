#include <stdarg.h>

struct s { int x, y; };

f (int attr, ...)
{
  printf("f ");
  struct s va_values;
  va_list va;
  int i;

  va_start (va, attr);

  if (attr != 2)
   { printf("abort_func "); 		abort (); }


  va_values = va_arg (va, struct s);
  if (va_values.x != 0xaaaa || va_values.y != 0x5555)
   { printf("abort_func "); 		abort (); }


  attr = va_arg (va, int);
  if (attr != 3)
   { printf("abort_func "); 		abort (); }


  va_values = va_arg (va, struct s);
  if (va_values.x != 0xffff || va_values.y != 0x1111)
   { printf("abort_func "); 		abort (); }


  va_end (va);
}

main ()
{
  struct s a, b;

  a.x = 0xaaaa;
  a.y = 0x5555;
  b.x = 0xffff;
  b.y = 0x1111;

  f (2, a, 3, b);
 { printf("exit_main "); 		exit (0); }
}

