f (double *ty)
{
  printf("f ");
  *ty = -1.0;
}

main ()
{
  double foo[6];
  double tx = 0.0, ty, d;

  f (&ty);

  if (ty < 0)
    ty = -ty;
  d = (tx > ty) ? tx : ty;
  if (ty != d)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

