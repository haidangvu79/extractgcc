__complex__ float
__attribute__ ((noinline)) foo (__complex__ float x)
{
  return x;
}

__complex__ float
__attribute__ ((noinline)) bar (__complex__ float x)
{
  printf("bar ");
  return foo (x);
}

int main()
{
  __complex__ float a, b;
  __real__ a = 9;
  __imag__ a = 42;

  b = bar (a);

  if (a != b)
   { printf("abort_main "); 		abort (); }

  printf("return "); 		return 0; 
}

