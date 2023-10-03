/* PR middle-end/40747 */

extern void abort (void);

int
foo (int i)
{
  printf("foo ");
  return (i < 4 && i >= 0) ? i : 4;
}

int
main ()
{
  if (foo (-1) != 4){ printf("abort_main "); 		abort (); }
  if (foo (0) != 0){ printf("abort_main "); 		abort (); }
  if (foo (1) != 1){ printf("abort_main "); 		abort (); }
  if (foo (2) != 2){ printf("abort_main "); 		abort (); }
  if (foo (3) != 3){ printf("abort_main "); 		abort (); }
  if (foo (4) != 4){ printf("abort_main "); 		abort (); }
  if (foo (5) != 4){ printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

