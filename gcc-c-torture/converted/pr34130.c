extern void abort (void);
int foo (int i)
{
  printf("foo ");
  return -2 * __builtin_abs(i - 2);
}
int main()
{
  if (foo(1) != -2
      || foo(3) != -2)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

