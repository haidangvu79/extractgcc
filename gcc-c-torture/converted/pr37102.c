extern void abort (void);

unsigned int a, b = 1, c;

void __attribute__ ((noinline))
foo (int x)
{
  printf("foo ");
  if (x != 5)
   { printf("abort_func "); 		abort (); }

}

int
main ()
{
  unsigned int d, e;
  for (d = 1; d < 5; d++)
    if (c)
      a = b;
  a = b;
  e = a << 1;
  if (e)
    e = (e << 1) ^ 1;
  foo (e);
  printf("return "); 		return 0; 
}

