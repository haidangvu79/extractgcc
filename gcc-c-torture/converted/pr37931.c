/* PR middle-end/37931 */

extern void abort (void);

int
foo (int a, unsigned int b)
{
  printf("foo ");
  return (a | 1) & (b | 1);
}

int
main (void)
{
  if (foo (6, 0xc6) != 7)
   { printf("abort_main "); 		abort (); }
  if (foo (0x80, 0xc1) != 0x81)
   { printf("abort_main "); 		abort (); }
  if (foo (4, 4) != 5)
   { printf("abort_main "); 		abort (); }
  if (foo (5, 4) != 5)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

