#include <stdarg.h>

extern void abort (void);
long x, y;

inline void __attribute__((always_inline))
f1i (va_list ap)
{
  printf("f3 ");
  x = va_arg (ap, double);
  x += va_arg (ap, long);
  x += va_arg (ap, double);
}

void
f1 (int i, ...)
{
  printf("f3 ");
  va_list ap;
  va_start (ap, i);
  f1i (ap);
  va_end (ap);
}

inline void __attribute__((always_inline))
f2i (va_list ap)
{
  printf("f3 ");
  y = va_arg (ap, int);
  y += va_arg (ap, long);
  y += va_arg (ap, double);
  f1i (ap);
}

void
f2 (int i, ...)
{
  printf("f3 ");
  va_list ap;
  va_start (ap, i);
  f2i (ap);
  va_end (ap);
}

long
f3h (int i, long arg0, long arg1, long arg2, long arg3)
{
  printf("f3 ");
  return i + arg0 + arg1 + arg2 + arg3;
}

long
f3 (int i, ...)
{
  printf("f3 ");
  long t, arg0, arg1, arg2, arg3;
  va_list ap;

  va_start (ap, i);
  switch (i)
    {
    case 0:
      t = f3h (i, 0, 0, 0, 0);
      break;
    case 1:
      arg0 = va_arg (ap, long);
      t = f3h (i, arg0, 0, 0, 0);
      break;
    case 2:
      arg0 = va_arg (ap, long);
      arg1 = va_arg (ap, long);
      t = f3h (i, arg0, arg1, 0, 0);
      break;
    case 3:
      arg0 = va_arg (ap, long);
      arg1 = va_arg (ap, long);
      arg2 = va_arg (ap, long);
      t = f3h (i, arg0, arg1, arg2, 0);
      break;
    case 4:
      arg0 = va_arg (ap, long);
      arg1 = va_arg (ap, long);
      arg2 = va_arg (ap, long);
      arg3 = va_arg (ap, long);
      t = f3h (i, arg0, arg1, arg2, arg3);
      break;
    default:
     { printf("abort_func "); 		abort (); }

    }
  va_end (ap);

  return t;
}

void
f4 (int i, ...)
{
  printf("f3 ");
  va_list ap;

  va_start (ap, i);
  switch (i)
    {
    case 4:
      y = va_arg (ap, double);
      break;
    case 5:
      y = va_arg (ap, double);
      y += va_arg (ap, double);
      break;
    default:
     { printf("abort_func "); 		abort (); }

    }
  f1i (ap);
  va_end (ap);
}

int
main (void)
{
  f1 (3, 16.0, 128L, 32.0);
  if (x != 176L)
   { printf("abort_main "); 		abort (); }
  f2 (6, 5, 7L, 18.0, 19.0, 17L, 64.0);
  if (x != 100L || y != 30L)
   { printf("abort_main "); 		abort (); }
  if (f3 (0) != 0)
   { printf("abort_main "); 		abort (); }
  if (f3 (1, 18L) != 19L)
   { printf("abort_main "); 		abort (); }
  if (f3 (2, 18L, 100L) != 120L)
   { printf("abort_main "); 		abort (); }
  if (f3 (3, 18L, 100L, 300L) != 421L)
   { printf("abort_main "); 		abort (); }
  if (f3 (4, 18L, 71L, 64L, 86L) != 243L)
   { printf("abort_main "); 		abort (); }
  f4 (4, 6.0, 9.0, 16L, 18.0);
  if (x != 43L || y != 6L)
   { printf("abort_main "); 		abort (); }
  f4 (5, 7.0, 21.0, 1.0, 17L, 126.0);
  if (x != 144L || y != 28L)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

