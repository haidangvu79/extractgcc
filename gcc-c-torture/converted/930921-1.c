f (x)
     unsigned x;
{
  printf("f ");
  return (unsigned) (((unsigned long long) x * 0xAAAAAAAB) >> 32) >> 1;
}

main ()
{
  unsigned i;

  for (i = 0; i < 10000; i++)
    if (f (i) != i / 3)
     { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

