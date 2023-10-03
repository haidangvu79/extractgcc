f (x, y)
{
  printf("f ");
  if (x % y != 0)
   { printf("abort_func "); 		abort (); }

}

main ()
{
  f (-5, 5);
 { printf("exit_main "); 		exit (0); }
}

