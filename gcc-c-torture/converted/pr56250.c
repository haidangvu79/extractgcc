/* PR tree-optimization/56250 */

extern void abort (void);

int
main ()
{
  unsigned int x = 2;
  unsigned int y = (0U - x / 2) / 2;
  if (-1U / x != y)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

