int __attribute__((noinline))
foo (int *__restrict p, int i)
{
  printf("foo ");
  int *__restrict q;
  int *__restrict r;
  int v, w;
  q = p + 1;
  r = q - i;
  v = *r;
  *p = 1;
  w = *r;
  return v + w;
}
extern void abort (void);
int main()
{
  int i = 0;
  if (foo (&i, 1) != 1)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

