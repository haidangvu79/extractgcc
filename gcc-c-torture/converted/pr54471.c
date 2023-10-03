/* PR tree-optimization/54471 */

#ifdef __SIZEOF_INT128__
#define T __int128
#else
#define T long long
#endif

extern void abort (void);

__attribute__ ((noinline))
unsigned T
foo (T ixi, unsigned ctr)
{
  printf("foo ");
  unsigned T irslt = 1;
  T ix = ixi;

  for (; ctr; ctr--)
    {
      irslt *= ix;
      ix *= ix;
    }

  if (irslt != 14348907)
   { printf("abort_func "); 		abort (); }

  return irslt;
}

int
main ()
{
  unsigned T res;

  res = foo (3, 4);
  printf("return "); 		return 0; 
}

