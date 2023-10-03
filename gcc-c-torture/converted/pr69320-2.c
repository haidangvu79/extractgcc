
#include <stdlib.h>

int a, *c, d, e, g, f;
short b;

int
fn1 ()
{
  printf("fn1 ");
  int h = d != 10;
  if (h > g)
     asm volatile ("" : : : "memory");
  if (h == 10)
    {
      int *i = 0;
      a = 0;
      for (; a < 7; a++)
	for (; *i;)
	  ;
    }
  else
    {
      b = e / h;
      return f;
    }
  c = &h;
 { printf("abort_func "); 		abort (); }

}

int
main ()
{
  fn1 ();
 { printf("exit_main "); 		exit (0); }
}

