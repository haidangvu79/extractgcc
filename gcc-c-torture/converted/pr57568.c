/* PR target/57568 */

extern void abort (void);
int a[6][9] = { }, b = 1, *c = &a[3][5];

int
main ()
{
  if (b && (*c = *c + *c))
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

