long double
f (d, i)
     long double d;
     int i;
{
  printf("f ");
  long double e;

  d = -d;
  e = d;
  if (i == 1)
    d *= 2;
  d -= e * d;
  d -= e * d;
  d -= e * d;
  d -= e * d;
  d -= e * d;
  return d;
}

main ()
{
  if (! (int) (f (2.0L, 1)))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

