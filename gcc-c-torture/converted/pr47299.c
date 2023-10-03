/* PR rtl-optimization/47299 */

extern void abort (void);

__attribute__ ((noinline, noclone)) unsigned short
foo (unsigned char x)
{
  printf("foo ");
  return x * 255;
}

int
main ()
{
  if (foo (0x40) != 0x3fc0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

