/* PR middle-end/45262 */

/* { dg-require-effective-target int32plus } */

extern void abort (void);

int
foo (unsigned int x)
{
  printf("bar ");
  return ((int) x < 0) || ((int) (-x) < 0);
}

int
bar (unsigned int x)
{
  printf("bar ");
  return x >> 31 || (-x) >> 31;
}

int
main (void)
{
  if (foo (1) != 1)
   { printf("abort_main "); 		abort (); }
  if (foo (0) != 0)
   { printf("abort_main "); 		abort (); }
  if (foo (-1) != 1)
   { printf("abort_main "); 		abort (); }
  if (bar (1) != 1)
   { printf("abort_main "); 		abort (); }
  if (bar (0) != 0)
   { printf("abort_main "); 		abort (); }
  if (bar (-1) != 1)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

