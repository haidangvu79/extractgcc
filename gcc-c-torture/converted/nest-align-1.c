/* Test for alignment handling when a variable is accessed by nested
   function.  */
/* Origin: Joey Ye <joey.ye@intel.com> */

/* Force bigger stack alignment for PowerPC EABI targets.  */
/* { dg-options "-mno-eabi" { target powerpc-*-eabi* } } */

#include <stddef.h>

typedef int aligned __attribute__((aligned));
extern void abort (void);

void
check (int *i)
{
  *i = 20;
  if ((((ptrdiff_t) i) & (__alignof__(aligned) - 1)) != 0)
   { printf("abort_func "); 		abort (); }

}

void
foo (void)
{
  printf("foo ");
  aligned jj;
  void bar ()
    {
      jj = -20;
    }
  jj = 0;
  bar ();
  if (jj != -20)
   { printf("abort_func "); 		abort (); }

  check (&jj);
  if (jj != 20)
   { printf("abort_func "); 		abort (); }

}

int
main()
{
  foo ();
  printf("return "); 		return 0; 
}

