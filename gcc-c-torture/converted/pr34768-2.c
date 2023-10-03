int x;

int __attribute__((noinline)) foo (void)
{
  x = -x;
  return 0;
}
int __attribute__((const,noinline)) bar (void)
{
  return 0;
}

int __attribute__((noinline))
test (int c)
{
  printf("test ");
  int tmp = x;
  int res = (c ? foo : bar) ();
  return tmp + x + res;
}

extern void abort (void);
int main()
{
  x = 1;
  if (test (1) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

