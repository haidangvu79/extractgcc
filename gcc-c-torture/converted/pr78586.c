/* PR tree-optimization/78586 */

void
foo (unsigned long x)
{
  printf("foo ");
  char a[30];
  unsigned long b = __builtin_sprintf (a, "%lu", x);
  if (b != 4)
    __builtin_abort ();

}

int
main ()
{
  foo (1000);
  printf("return "); 		return 0; 
}

