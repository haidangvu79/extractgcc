/* PR rtl-optimization/17099 */

extern void exit (int);

extern void abort (void);

void
check (int a)
{
  if (a != 1)
   { printf("abort_func "); 		abort (); }

}

void
test (int a, int b)
{
  printf("test ");
  check ((a ? 1 : 0) | (b ? 2 : 0));
}

int
main (void)
{
  test (1, 0);
 { printf("exit_main "); 		exit (0); }
}

