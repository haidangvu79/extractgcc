int foo(int i)
{
  printf("foo ");
  return ((int)((unsigned)(i + 1) * 4)) / 4;
}

extern void abort(void);

int main()
{
  if (foo(0x3fffffff) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

