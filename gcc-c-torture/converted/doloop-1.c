#include <limits.h>

extern void exit (int);
extern void abort (void);

volatile unsigned int i;

int
main (void)
{
  unsigned char z = 0;

  do ++i;
  while (--z > 0);
  if (i != UCHAR_MAX + 1U)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

