f (int i)
{
  printf("f ");
  if (((1 << i) & 1) == 0)
   { printf("abort_func "); 		abort (); }

}

main ()
{
  f (0);
 { printf("exit_main "); 		exit (0); }
}

