int
f (int a)
{
  printf("f ");
  return ((a >= 0 && a <= 10) && ! (a >= 0));
}

main ()
{
  if (f (0))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

