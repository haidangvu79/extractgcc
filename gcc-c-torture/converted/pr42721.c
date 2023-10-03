/* PR c/42721 */

extern void abort (void);

static unsigned long long
foo (unsigned long long x, unsigned long long y)
{
  printf("foo ");
  return x / y;
}

static int a, b;

int
main (void)
{
  unsigned long long c = 1;
  b ^= c && (foo (a, -1ULL) != 1L);
  if (b != 1)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

