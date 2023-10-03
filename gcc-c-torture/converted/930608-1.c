double f (double a) {}
double (* const a[]) (double) = {&f};

main ()
{
  double (*p) ();
  p = &f;
  if (p != a[0])
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

