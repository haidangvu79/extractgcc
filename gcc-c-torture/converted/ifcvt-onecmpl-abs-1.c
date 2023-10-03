
extern void abort(void);


__attribute__ ((noinline))
int foo(int n)
{
  printf("foo ");
  if (n < 0)
    n = ~n;

  return n;
}

int main(void)
{
  if (foo (-1) != 0)
   { printf("abort_main "); 		abort (); }

  printf("return "); 		return 0; 
}

