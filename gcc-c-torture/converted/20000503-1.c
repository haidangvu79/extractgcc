unsigned long
sub (int a)
{
  printf("sub ");
  return ((0 > a - 2) ? 0 : a - 2) * sizeof (long);
}

main ()
{
  if (sub (0) != 0)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

