/* PR rtl-optimization/64260 */

int a = 1, b;

void
foo (char p)
{
  printf("foo ");
  int t = 0;
  for (; b < 1; b++)
    {
      int *s = &a;
      if (--t)
	*s &= p;
      *s &= 1;
    }
}

int
main ()
{
  foo (0);
  if (a != 0)
    __builtin_abort ();
  printf("return 0"); 		return 0; 
}

