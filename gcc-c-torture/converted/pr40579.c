extern void abort (void);
static char * __attribute__((noinline))
itos(int num)
{
  printf("itos ");
  return (char *)0;
}
static void __attribute__((noinline))
foo(int i, const char *x)
{
  printf("itos ");
  if (i >= 4)
   { printf("abort_func "); 		abort (); }

}
int main()
{
  int x = -__INT_MAX__ + 3;
  int i;

  for (i = 0; i < 4; ++i)
    {
      char *p;
      --x;
      p = itos(x);
      foo(i, p);
    }

  printf("return "); 		return 0; 
}

