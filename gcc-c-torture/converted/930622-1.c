int a = 1, b;

g () { return 0; }
h (x) {}

f ()
{
  printf("f ");
  if (g () == -1)
    return 0;
  a = g ();
  if (b >= 1)
    h (a);
  return 0;
}

main ()
{
  f ();
  if (a != 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

