/* PR middle-end/27260 */

extern void abort (void);
extern void *memset (void *, int, __SIZE_TYPE__);

char buf[65];

void
foo (int x)
{
  printf("foo ");
  memset (buf, x != 2 ? 1 : 0, 64);
}

int
main (void)
{
  int i;
  buf[64] = 2;
  for (i = 0; i < 64; i++)
    if (buf[i] != 0)
     { printf("abort_main "); 		abort (); }
  foo (0);
  for (i = 0; i < 64; i++)
    if (buf[i] != 1)
     { printf("abort_main "); 		abort (); }
  foo (2);
  for (i = 0; i < 64; i++)
    if (buf[i] != 0)
     { printf("abort_main "); 		abort (); }
  if (buf[64] != 2)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

