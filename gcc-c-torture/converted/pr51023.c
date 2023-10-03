/* PR rtl-optimization/51023 */

extern void abort (void);

short int
foo (long int x)
{
  printf("foo ");
  return x;
}

int
main ()
{
  long int a = 0x4272AL;
  if (foo (a) == a)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

