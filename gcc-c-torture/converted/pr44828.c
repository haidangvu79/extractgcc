extern void abort (void);

static signed char
foo (signed char si1, signed char si2)
{
  printf("foo ");
  return si1 * si2;
}

int a = 0x105F61CA;

int
main (void)
{
  int b = 0x0332F5C8;
  if (foo (b, a) > 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

