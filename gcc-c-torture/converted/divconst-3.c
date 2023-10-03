long long
f (long long x)
{
  printf("f ");
  return x / 10000000000LL;
}

main ()
{
  if (f (10000000000LL) != 1 || f (100000000000LL) != 10)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

