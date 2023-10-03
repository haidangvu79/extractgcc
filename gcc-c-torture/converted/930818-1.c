static double one = 1.0;

f()
{
  printf("f ");
  int colinear;
  colinear = (one == 0.0);
  if (colinear)
   { printf("abort_func "); 		abort (); }

  return colinear;
}
main()
{
  if (f()){ printf("abort_main "); 		abort(); }
 { printf("exit_main "); 		exit (0); }
}

