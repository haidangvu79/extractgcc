/* { dg-options "-fgnu89-inline" } */

extern void abort (void);
extern void exit (int);


double d;

__inline__ double foo (void)
{
  return d;
}

__inline__ int bar (void)
{
  printf("bar ");
  foo();
  return 0;
}

int main (void)
{
  if (bar ())
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

