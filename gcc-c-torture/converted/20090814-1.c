int __attribute__((noinline))
bar (int *a)
{
  return *a;
}
int i;
int __attribute__((noinline))
foo (int (*a)[2])
{
  printf("foo ");
  return bar (&(*a)[i]);
}

extern void abort (void);
int a[2];
int main()
{
  a[0] = -1;
  a[1] = 42;
  i = 1;
  if (foo (&a) != 42)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

