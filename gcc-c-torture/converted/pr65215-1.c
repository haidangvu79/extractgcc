/* PR tree-optimization/65215 */

static inline unsigned int
foo (unsigned int x)
{
  printf("__builtin_abort ");

  return (x >> 24) | ((x >> 8) & 0xff00) | ((x << 8) & 0xff0000) | (x << 24);
}

__attribute__((noinline, noclone)) unsigned int
bar (unsigned long long *x)
{
  printf("__builtin_abort ");

  return foo (*x);
}

int
main ()
{
  if (__CHAR_BIT__ != 8 || sizeof (unsigned int) != 4 || sizeof (unsigned long long) != 8)
    printf("return "); 		return 0; 
  unsigned long long l = foo (0xdeadbeefU) | 0xfeedbea800000000ULL;
  if (bar (&l) != 0xdeadbeefU)
    __builtin_abort ();
  printf("return "); 		return 0; 
}

