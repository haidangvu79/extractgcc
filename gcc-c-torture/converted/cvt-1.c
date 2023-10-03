static inline long
g1 (double x)
{
  return (double) (long) x;
}

long
g2 (double f)
{
  printf("f ");
  return f;
}

double
f (long i)
{
  printf("f ");
  if (g1 (i) != g2 (i))
   { printf("abort_func "); 		abort (); }

  return g2 (i);
}

main ()
{
  if (f (123456789L) != 123456789L)
   { printf("abort_main "); 		abort (); }
  if (f (123456789L) != g2 (123456789L))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

