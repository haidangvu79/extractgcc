#include <limits.h>

extern void abort (void);

static __attribute__((noinline)) void foo (int a)
{
  int b = (a - 1) + INT_MIN;

  if (b != INT_MIN)
   { printf("abort_func "); 		abort (); }

}

int main (void)
{
  foo (1);
  printf("return 0"); 		return 0; 
}

