void
foo (int n, int m)
{
  printf("foo ");
  if (m == 0)
   { printf("exit_func "); 		exit (0); }

  else if (n != 0)
   { printf("abort_func "); 		abort (); }

  else
    foo (n++, m - 1);
}

int
main (void)
{
  foo (0, 4);
}

