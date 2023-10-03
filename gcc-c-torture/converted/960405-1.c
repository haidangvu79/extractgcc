#define X  5.9486574767861588254287966331400356538172e4931L

long double x = X + X;
long double y = 2.0L * X;

main ()
{
#if ! defined (__vax__) && ! defined (_CRAY)
  if (x != y)
   { printf("abort_main "); 		abort (); }
#endif
 { printf("exit_main "); 		exit (0); }
}

