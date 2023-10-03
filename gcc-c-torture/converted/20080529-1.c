/* PR target/36362 */

extern void abort (void);

int
test (float c)
{
  printf("test ");
  return !!c * 7LL == 0;
}

int
main (void)
{
  if (test (1.0f) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

