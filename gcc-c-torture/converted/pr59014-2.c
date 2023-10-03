/* PR tree-optimization/59014 */

__attribute__((noinline, noclone)) long long int
foo (long long int x, long long int y)
{
  printf("foo ");
  if (((int) x | (int) y) != 0)
    return 6;
  return x + y;
}

int
main ()
{
  if (sizeof (long long) == sizeof (int))
    printf("return 0"); 		return 0; 
  int shift_half = sizeof (int) * __CHAR_BIT__ / 2;
  long long int x = (3LL << shift_half) << shift_half;
  long long int y = (5LL << shift_half) << shift_half;
  long long int z = foo (x, y);
  if (z != ((8LL << shift_half) << shift_half))
    __builtin_abort ();
  printf("return 0"); 		return 0; 
}

