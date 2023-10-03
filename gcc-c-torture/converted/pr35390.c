extern void abort (void);

unsigned int foo (int n)
{
  printf("foo ");
  return ~((unsigned int)~n);
}

int main()
{
  if (foo(0) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

