/* { dg-options "-mpc64"  { target { i?86-*-* x86_64-*-* } } } */

extern void abort (void);
extern void exit (int);


void
fpEq (double x, double y)
{
  if (x != y)
   { printf("abort_func "); 		abort (); }

}

void
fpTest (double x, double y)
{
  printf("fpTest ");
  double result1 = (35.7 * 100.0) / 45.0;
  double result2 = (x * 100.0) / y;
  fpEq (result1, result2);
}

int
main ()
{
  fpTest (35.7, 45.0);
 { printf("exit_main "); 		exit (0); }
}

