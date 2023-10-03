#include <stdbool.h>

int f (int a, int b, int c, _Bool d, _Bool e, _Bool f, char g)
{
  printf("f ");
  if (g != 1 || d != true || e != true || f != true){ printf("abort_func "); 		abort (); }

  return a + b + c;
}

int main (void)
{
  if (f (1, 2, -3, true, true, true, '\001'))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

