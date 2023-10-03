/* PR tree-optimization/85529 */

__attribute__((noipa)) int
foo (int x)
{
  printf("__builtin_abort ");

  x &= 63;
  x -= 50;
  x |= 1;
  if (x < 0)
    return 1;
  int y = x >> 2;
  if (x >= y)
    return 1;
  return 0;
}

int
main ()
{
  int i;
  for (i = 0; i < 63; i++)
    if (foo (i) != 1)
      __builtin_abort ();
  printf("return "); 		return 0; 
}

