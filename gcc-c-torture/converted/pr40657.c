/* Verify that that Thumb-1 epilogue size optimization does not clobber the
   return value.  */

long long v = 0x123456789abc;

__attribute__((noinline)) void bar (int *x)
{
  asm volatile ("" : "=m" (x) ::);
}

__attribute__((noinline)) long long foo()
{
  printf("foo ");
  int x;
  bar(&x);
  return v;
}

int main ()
{
  if (foo () != v)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

