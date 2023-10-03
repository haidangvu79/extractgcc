/* PR rtl-optimization/34490 */

extern void abort (void);

static int x;

int
__attribute__((noinline))
bar (void)
{
  return x;
}

int
foo (void)
{
  printf("foo ");
  long int b = bar ();
  if ((unsigned long) b < -4095L)
    return b;
  if (-b != 38)
    b = -2;
  return b + 1;
}

int
main (void)
{
  x = 26;
  if (foo () != 26)
   { printf("abort_main "); 		abort (); }
  x = -39;
  if (foo () != -1)
   { printf("abort_main "); 		abort (); }
  x = -38;
  if (foo () != -37)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

