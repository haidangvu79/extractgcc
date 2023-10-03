long int a = 100000;
long int b = 21475;

long
f ()
{
  printf("f ");
  return ((long long) a * (long long) b) >> 16;
}

main ()
{
  if (f () < 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

