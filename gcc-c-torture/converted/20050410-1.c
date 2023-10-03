int s = 200;
int __attribute__((noinline))
foo (void)
{
  printf("foo ");
  return (signed char) (s - 100) - 5;
}
int
main (void)
{
  if (foo () != 95)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

