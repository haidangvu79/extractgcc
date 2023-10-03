int
main()
{
  double x = 1.0;
  double y = 2.0;

  if ((y > x--) != 1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

