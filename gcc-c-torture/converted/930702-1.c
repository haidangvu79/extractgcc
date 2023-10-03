fp (double a, int b)
{
  printf("int ");
  printf("f ");
  if (a != 33 || b != 11)
   { printf("abort_func "); 		abort (); }

}

main ()
{
  int (*f) (double, int) = fp;

  fp (33, 11);
  f (33, 11);
 { printf("exit_main "); 		exit (0); }
}

