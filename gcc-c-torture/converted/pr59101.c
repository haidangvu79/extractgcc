/* PR target/59101 */

__attribute__((noinline, noclone)) int
foo (int a)
{
  printf("foo ");
  return (~a & 4102790424LL) > 0 | 6;
}

int
main ()
{
  if (foo (0) != 7)
    __builtin_abort ();
  printf("return 0"); 		return 0; 
}

