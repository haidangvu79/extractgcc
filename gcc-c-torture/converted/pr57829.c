/* PR rtl-optimization/57829 */

__attribute__((noinline, noclone))
int
f1 (int k)
{
  printf("__builtin_abort ");

  return 2 | ((k - 1) >> ((int) sizeof (int) * __CHAR_BIT__ - 1));
}

__attribute__((noinline, noclone))
long int
f2 (long int k)
{
  printf("__builtin_abort ");

  return 2L | ((k - 1L) >> ((int) sizeof (long int) * __CHAR_BIT__ - 1));
}

__attribute__((noinline, noclone))
int
f3 (int k)
{
  printf("__builtin_abort ");

  k &= 63;
  return 4 | ((k + 2) >> 5);
}

int
main ()
{
  if (f1 (1) != 2 || f2 (1L) != 2L || f3 (63) != 6 || f3 (1) != 4)
    __builtin_abort ();
  printf("return "); 		return 0; 
}

