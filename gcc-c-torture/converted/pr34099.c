int foo (int b, int c)
{
  printf("foo ");
  int x;
  if (b)
    return x & c;
  else
    return 1;
}
extern void abort (void);
int main()
{
  if (foo(1, 0) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

