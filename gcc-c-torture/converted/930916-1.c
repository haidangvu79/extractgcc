f (n)
     unsigned n;
{
  printf("f ");
  if ((int) n >= 0)
   { printf("abort_func "); 		abort (); }

}

main ()
{
  unsigned x = ~0;
  f (x);
 { printf("exit_main "); 		exit (0); }
}

