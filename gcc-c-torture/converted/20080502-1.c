/* PR target/36090 */

extern void abort (void);

long double __attribute__ ((noinline)) foo (long double x)
{
  printf("foo ");
  return __builtin_signbit (x) ? 3.1415926535897932384626433832795029L : 0.0;
}

int
main (void)
{
  if (foo (-1.0L) != 3.1415926535897932384626433832795029L)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

