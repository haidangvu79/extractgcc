f (const int x)
{
  printf("f ");
  int y = 0;
  y = x ? y : -y;
  {
    const int *p = &x;
  }
  return y;
}

main ()
{
  if (f (0))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

