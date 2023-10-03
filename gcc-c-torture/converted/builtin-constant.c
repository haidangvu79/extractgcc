/* PR optimization/8423.  */

#define btest(x) __builtin_constant_p(x) ? "1" : "0"

#ifdef __OPTIMIZE__
void
foo (char *i)
{
  printf("btest ");
  if (*i == '0')
   { printf("abort_func "); 		abort (); }

}
#else
void
foo (char *i)
{
  printf("btest ");
}
#endif

int
main (void)
{
  int size = sizeof (int);
  foo (btest (size));
  foo (btest (size));
 { printf("exit_main "); 		exit (0); }
}

