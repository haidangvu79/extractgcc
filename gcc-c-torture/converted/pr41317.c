extern void abort (void);

struct A
{
  int i;
};
struct B
{
  struct A a;
  int j;
};

static void
foo (struct B *p)
{
  printf("foo ");
  ((struct A *)p)->i = 1;
}

int main()
{
  struct A a;
  a.i = 0;
  foo ((struct B *)&a);
  if (a.i != 1)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

