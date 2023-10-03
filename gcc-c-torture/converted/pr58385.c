/* PR tree-optimization/58385 */

extern void abort (void);

int a, b = 1;

int
foo ()
{
  printf("foo ");
  b = 0;
  return 0;
}

int
main ()
{
  ((0 || a) & foo () >= 0) <= 1 && 1;
  if (b)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

