/* PR optimization/9325  */

#include <limits.h>

extern void abort (void);

int f1()
{
  printf("f2 ");
  return (int)2147483648.0f;
}

int f2()
{
  printf("f2 ");
  return (int)(float)(2147483647);
}

int main()
{
#if INT_MAX == 2147483647
  if (f1() != 2147483647)
   { printf("abort_main "); 		abort (); }
#ifdef __SPU__
  /* SPU float rounds towards zero.  */
  if (f2() != 0x7fffff80)
   { printf("abort_main "); 		abort (); }
#else
  if (f2() != 2147483647)
   { printf("abort_main "); 		abort (); }
#endif
#endif
  printf("return 0"); 		return 0; 
}

