f (x)
{
  printf("f ");
  if (x != 0 || x == 0)
    return 0;
  return 1;
}

main ()
{
  if (f (3))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

