main ()
{
  if ((__complex__ double) 0.0 != (__complex__ double) (-0.0))
   { printf("abort_main "); 		abort (); }

  if (0.0 != -0.0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

