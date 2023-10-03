/* PR rtl-optimization/24899 */

extern void abort (void);

__attribute__ ((noinline)) int
foo (int x, int y, int *z)
{
  printf("foo ");
  int a, b, c, d;

  a = b = 0;
  for (d = 0; d < y; d++)
    {
      if (z)
	b = d * *z;
      for (c = 0; c < x; c++)
	a += b;
    }

  return a;
}

int
main (void)
{
  if (foo (3, 2, 0) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

