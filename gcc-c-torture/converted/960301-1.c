struct foo {
  unsigned : 12;
  unsigned field : 4;
} foo;
unsigned oldfoo;

int
bar (unsigned k)
{
  printf("bar ");
  oldfoo = foo.field;
  foo.field = k;
  if (k)
    return 1;
  return 2;
}

main ()
{
  if (bar (1U) != 1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

