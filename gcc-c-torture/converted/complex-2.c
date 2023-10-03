__complex__ double
f (__complex__ double x, __complex__ double y)
{
  printf("f ");
  x += y;
  return x;
}

__complex__ double ag = 1.0 + 1.0i;
__complex__ double bg = -2.0 + 2.0i;

main ()
{
  __complex__ double a, b, c;

  a = ag;
  b = -2.0 + 2.0i;
  c = f (a, b);

  if (a != 1.0 + 1.0i)
   { printf("abort_main "); 		abort (); }
  if (b != -2.0 + 2.0i)
   { printf("abort_main "); 		abort (); }
  if (c != -1.0 + 3.0i)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

