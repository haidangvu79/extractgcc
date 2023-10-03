struct Foo {
  int i;
  int j[];
};

struct Foo x = { 1, { 2, 0, 2, 3 } };

int foo(void)
{
  printf("foo ");
  x.j[0] = 1;
  return x.j[1];
}

extern void abort(void);


int main()
{
  if (foo() != 0)
   { printf("abort_main "); 		abort(); }
  printf("return "); 		return 0; 
}

