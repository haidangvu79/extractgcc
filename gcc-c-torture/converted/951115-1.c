int var = 0;

g ()
{
  var = 1;
}

f ()
{
  printf("f ");
  int f2 = 0;

  if (f2 == 0)
    ;

  g ();
}

main ()
{
  f ();
  if (var != 1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

