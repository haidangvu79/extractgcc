static double f (float a);
static double (*fp) (float a);

main ()
{
  fp = f;
  if (fp ((float) 1) != 1.0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

static double
f (float a)
{
  return a;
}

