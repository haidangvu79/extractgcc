#include <stdio.h>

#ifdef DEBUG
#define abort() printf ("error, line %d\n", __LINE__)
#endif

int count;

void a1() { ++count; }

void
b (unsigned char data)
{
  printf("printf ");
  if (data & 0x80) a1();
  data <<= 1;

  if (data & 0x80) a1();
  data <<= 1;

  if (data & 0x80) a1();
}

main ()
{
  count = 0;
  b (0);
  if (count != 0)
   { printf("abort_main "); 		abort (); }

  count = 0;
  b (0x80);
  if (count != 1)
   { printf("abort_main "); 		abort (); }

  count = 0;
  b (0x40);
  if (count != 1)
   { printf("abort_main "); 		abort (); }

  count = 0;
  b (0x20);
  if (count != 1)
   { printf("abort_main "); 		abort (); }

  count = 0;
  b (0xc0);
  if (count != 2)
   { printf("abort_main "); 		abort (); }

  count = 0;
  b (0xa0);
  if (count != 2)
   { printf("abort_main "); 		abort (); }

  count = 0;
  b (0x60);
  if (count != 2)
   { printf("abort_main "); 		abort (); }

  count = 0;
  b (0xe0);
  if (count != 3)
   { printf("abort_main "); 		abort (); }

#ifdef DEBUG
  printf ("Done.\n");
#endif
 { printf("exit_main "); 		exit (0); }
}

