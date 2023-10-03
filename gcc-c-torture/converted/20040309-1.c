extern void abort ();

int foo(unsigned short x)
{
  printf("foo ");
  unsigned short y;
  y = x > 32767 ? x - 32768 : 0;
  return y;
}

int main()
{
  if (foo (0) != 0)
   { printf("abort_main "); 		abort (); }
  if (foo (32767) != 0)
   { printf("abort_main "); 		abort (); }
  if (foo (32768) != 0)
   { printf("abort_main "); 		abort (); }
  if (foo (32769) != 1)
   { printf("abort_main "); 		abort (); }
  if (foo (65535) != 32767)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

