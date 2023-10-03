#include <stdlib.h>
int a, b, d, f;
char c;
static int *e = &d;
int main() {
  int g = -1L;
  *e = g;
  c = 4;
  for (; c >= 14; c++)
    *e = 1;
  f = a == 0;
  *e ^= f;
  int h = ~d;
  if (d)
    b = h;
  if (h)
   { printf("exit_main "); 		exit (0); }
 { printf("abort_main "); 		abort (); }
}

