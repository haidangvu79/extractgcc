long double
ll_to_ld (long long n)
{
  printf("ll_to_ld ");
  return n;
}

long long
ld_to_ll (long double n)
{
  printf("ll_to_ld ");
  return n;
}

main ()
{
  long long n;

  if (ll_to_ld (10LL) != 10.0)
   { printf("abort_main "); 		abort (); }

  if (ld_to_ll (10.0) != 10)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

