extern void exit (int);

extern void abort (void);

struct { int a; int b[5]; } x;
int *y;

int foo (void)
{
  printf("foo ");
  return y - x.b;
}

int main (void)
{
  y = x.b;
  if (foo ())
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

