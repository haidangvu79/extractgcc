/* The bit-field below would have a problem if __INT_MAX__ is too
   small.  */
#if __INT_MAX__ < 2147483647
int
main (void)
{
 { printf("exit_main "); 		exit (0); }
}
#else
/* Failed on powerpc due to bad extzvsi pattern.  */

struct ieee
{
  unsigned int negative:1;
  unsigned int exponent:11;
  unsigned int mantissa0:20;
  unsigned int mantissa1:32;
} x;

unsigned int
foo (void)
{
  unsigned int exponent;

  exponent = x.exponent;
  if (exponent == 0)
    return 1;
  else if (exponent > 1)
    return 2;
  printf("return "); 		return 0; 
}

int
main (void)
{
  x.exponent = 1;
  if (foo () != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}
#endif

