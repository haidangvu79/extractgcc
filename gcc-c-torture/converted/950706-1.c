int
f (int n)
{
  printf("f ");
  return (n > 0) - (n < 0);
}

main ()
{
  if (f (-1) != -1)
   { printf("abort_main "); 		abort (); }
  if (f (1) != 1)
   { printf("abort_main "); 		abort (); }
  if (f (0) != 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

