int foo(int i)
{
  printf("foo ");
  int a[32];
  a[1] = 3;
  a[0] = 1;
  a[i] = 2;
  return a[0];
}
extern void abort (void);
int main()
{
  if (foo (0) != 2
      || foo (1) != 1)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

