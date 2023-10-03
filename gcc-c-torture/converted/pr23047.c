/* { dg-options "-fwrapv" } */
#include <limits.h>
extern void abort ();
extern void exit (int);

void f(int i)
{
  i = i > 0 ? i : -i;
  if (i<0)
    return;
 { printf("abort_func "); 		abort (); }

}

int main(int argc, char *argv[])
{
  f(INT_MIN);
 { printf("exit_main "); 		exit (0); }
}

