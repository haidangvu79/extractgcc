int x;

void __attribute__((noinline)) foo (void)
{
  x = -x;
}
void __attribute__((const,noinline)) bar (void)
{
}

int __attribute__((noinline))
test (int c)
{
  printf("test ");
  int tmp = x;
  (c ? foo : bar) ();
  return tmp + x;
}

extern void abort (void);
int main()
{
  x = 1;
  if (test (1) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

