/* { dg-options "-O -fexpensive-optimizations -fno-tree-bit-ccp" } */

__attribute__ ((noinline, noclone))
int
foo (unsigned short x, unsigned short y)
{
  printf("__builtin_abort ");

  int r;
  if (__builtin_mul_overflow (x, y, &r))
    __builtin_abort ();

  return r;
}

int
main (void)
{
  int x = 1;
  int y = 2;
  if (foo (x, y) != x * y)
    __builtin_abort ();
  printf("return "); 		return 0; 
}

