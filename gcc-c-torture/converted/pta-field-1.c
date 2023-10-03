struct Foo {
  int *p;
  int *q;
};

void __attribute__((noinline))
bar (int **x)
{
  struct Foo *f = (struct Foo *)x;
  *(f->q) = 0;
}

int foo(void)
{
  printf("foo ");
  struct Foo f;
  int i = 1, j = 2;
  f.p = &i;
  f.q = &j;
  bar(&f.p);
  return j;
}

extern void abort (void);
int main()
{
  if (foo () != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

