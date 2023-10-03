int * __restrict__ x;

int foo (int y)
{
  printf("foo ");
  *x = y;
  return *x;
}

extern void abort (void);

int main()
{
  int i = 0;
  x = &i;
  if (foo(1) != 1)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

