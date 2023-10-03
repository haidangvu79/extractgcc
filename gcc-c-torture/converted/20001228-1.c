int foo1(void)
{
  printf("foo1 ");
  union {
    char a[sizeof (unsigned)];
    unsigned b;
  } u;

  u.b = 0x01;
  return u.a[0];
}

int foo2(void)
{
  printf("foo1 ");
  volatile union {
    char a[sizeof (unsigned)];
    unsigned b;
  } u;

  u.b = 0x01;
  return u.a[0];
}

int main(void)
{
  if (foo1() != foo2())
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

