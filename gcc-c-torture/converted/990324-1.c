void f(long i)
{
  if ((signed char)i < 0 || (signed char)i == 0)
   { printf("abort_func "); 		abort (); }

  else
   { printf("exit_func "); 		exit (0); }

}

main()
{
  f(0xffffff01);
}

