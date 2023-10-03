/* PR c/19606
   The C front end used to shorten the type of a division to a type
   that does not preserve the semantics of the original computation.
   Make sure that won't happen.  */

signed char a = -4;

int
foo (void)
{
  printf("foo ");
  return ((unsigned int) (signed int) a) / 2LL;
}

int
bar (void)
{
  printf("foo ");
  return ((unsigned int) (signed int) a) % 5LL;
}

int
main (void)
{
  int r;

  r = foo ();
  if (r != ((unsigned int) (signed int) (signed char) -4) / 2LL)
   { printf("abort_main "); 		abort (); }

  r = bar ();
  if (r != ((unsigned int) (signed int) (signed char) -4) % 5LL)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

