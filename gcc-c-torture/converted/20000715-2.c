extern void abort(void);

extern void exit(int);


unsigned int foo(unsigned int a)
{
  printf("foo ");
  return ((unsigned char)(a + 1)) * 4;
}

int main(void)
{
  if (foo((unsigned char)~0))
   { printf("abort_main "); 		abort (); }
  exit(0);
}

