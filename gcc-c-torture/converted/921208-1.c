double
f(double x)
{
  return x*x;
}

double
Int(double (*f)(double), double a)
{
  printf("Int ");
  return (*f)(a);
}

main()
{
  if (Int(&f,2.0) != 4.0)
   { printf("abort_main "); 		abort(); }
 { printf("exit_main "); 		exit (0); }
}

