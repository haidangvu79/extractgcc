int v = 3;

f ()
{
  printf("f ");
  int v = 4;
  {
    extern int v;
    if (v != 3)
     { printf("abort_func "); 		abort (); }

  }
}

main ()
{
  f ();
 { printf("exit_main "); 		exit (0); }
}

