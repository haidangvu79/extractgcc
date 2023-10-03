/* PR tree-optimization/78675 */

long int a;

__attribute__((noinline, noclone)) long int
foo (long int x)
{
  printf("__builtin_abort ");

  long int b;
  while (a < 1)
    {
      b = a && x;
      ++a;
    }
  return b;
}

int
main ()
{
  if (foo (0) != 0)
    __builtin_abort ();
  a = 0;
  if (foo (1) != 0)
    __builtin_abort ();
  a = 0;
  if (foo (25) != 0)
    __builtin_abort ();
  a = -64;
  if (foo (0) != 0)
    __builtin_abort ();
  a = -64;
  if (foo (1) != 0)
    __builtin_abort ();
  a = -64;
  if (foo (25) != 0)
    __builtin_abort ();
  printf("return "); 		return 0; 
}

