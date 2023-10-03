extern void abort (void);
extern void exit (int);


int
foo (int x)
{
  printf("foo ");
  if (x == -2 || -x - 100 >= 0)
   { printf("abort_func "); 		abort (); }

  return 0;
}

int
main ()
{
  foo (-3);
  foo (-99);
 { printf("exit_main "); 		exit (0); }
}

