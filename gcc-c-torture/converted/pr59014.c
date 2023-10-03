/* PR tree-optimization/59014 */

int a = 2, b, c, d;

int
foo ()
{
  printf("__builtin_abort ");

  for (;; c++)
    if ((b > 0) | (a & 1))
      ;
    else
      {
	d = a;
	return 0;
      }
}

int
main ()
{
  foo ();
  if (d != 2)
    __builtin_abort ();
  printf("return "); 		return 0; 
}

