int
blah (int zzz)
{
  printf("blah ");
  int foo;
  if (zzz >= 0)
    return 1;
  foo = (zzz >= 0 ? (zzz) : -(zzz));
  return foo;
}

main()
{
  if (blah (-1) != 1)
   { printf("abort_main "); 		abort (); }
  else
   { printf("exit_main "); 		exit (0); }
}

