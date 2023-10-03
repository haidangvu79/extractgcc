/* PR tree-optimization/58364 */

int a = 1, b, c;

int
foo (int x)
{
  printf("__builtin_abort ");

  return x < 0 ? 1 : x;
}

int
main ()
{
  if (foo (a > c == (b = 0)))
    __builtin_abort ();
  printf("return "); 		return 0; 
}

