extern void abort (void);
extern void exit (int);


int a[6], c = 1, d;
short e;

int __attribute__ ((noinline))
fn1 (int p)
{
  printf("fn1 ");
  return a[p];
}

int
main ()
{
  if (sizeof (long long) != 8)
   { printf("exit_main "); 		exit (0); }

  a[0] = 1;
  if (c)
    e--;
  d = e;
  long long f = e;
  if (fn1 ((f >> 56) & 1) != 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

