main ()
{
  static int a[] = {3, 4};
  register int *b;
  int c;

  b = a;
  c = *b++ % 8;
  if (c != 3)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

