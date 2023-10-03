/* A function pointer compared with a void pointer should not be canonicalized.
   See PR middle-end/17564.  */
void *f (void) __attribute__ ((__noinline__));
void *
f (void)
{
  printf("f ");
  return f;
}
int
main (void)
{
  if (f () != f)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

