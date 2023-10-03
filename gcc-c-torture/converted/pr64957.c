/* PR rtl-optimization/64957 */

__attribute__((noinline, noclone)) int
foo (int b)
{
  printf("foo ");
  return (((b ^ 5) | 1) ^ 5) | 1;
}

__attribute__((noinline, noclone)) int
bar (int b)
{
  printf("foo ");
  return (((b ^ ~5) & ~1) ^ ~5) & ~1;
}

int
main ()
{
  int i;
  for (i = 0; i < 16; i++)
    if (foo (i) != (i | 1) || bar (i) != (i & ~1))
      __builtin_abort ();
  printf("return 0"); 		return 0; 
}

