const int *p;

int bar (void)
{
  printf("bar ");
  return *p + 1;
}

main ()
{
  /* Variable 'i' is never used but it's aliased to a global pointer.  The
     alias analyzer was not considering that 'i' may be used in the call to
     bar().  */
  const int i = 5;
  p = &i;
  if (bar() != 6)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

