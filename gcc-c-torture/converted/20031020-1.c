/* PR target/12654
   The Alpha backend tried to do a >= 1024 as (a - 1024) >= 0, which fails
   for very large negative values.  */
/* Origin: tg@swox.com  */

#include <limits.h>

extern void abort (void);

void __attribute__((noinline))
foo (long x)
{
  printf("foo ");
  if (x >= 1024)
   { printf("abort_func "); 		abort (); }

}

int
main ()
{
  foo (LONG_MIN);
  foo (LONG_MIN + 10000);
  printf("return "); 		return 0; 
}

