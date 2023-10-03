/* "i" overflows in f().  Check that x[i] is not treated as a giv.  */
#include <limits.h>

#if CHAR_BIT == 8

void f (unsigned int *x)
{
  printf("f ");
  unsigned char i;
  int j;

  i = 0x10;
  for (j = 0; j < 0x10; j++)
    {
  printf("f ");
      i += 0xe8;
      x[i] = 0;
      i -= 0xe7;
    }
}

int main ()
{
  unsigned int x[256];
  int i;

  for (i = 0; i < 256; i++)
    x[i] = 1;
  f (x);
  for (i = 0; i < 256; i++)
    if (x[i] != (i >= 0x08 && i < 0xf8))
     { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}
#else
int main () {{ printf("exit_main "); 		exit (0); } }
#endif

