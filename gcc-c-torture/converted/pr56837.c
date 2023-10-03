extern void abort (void);
_Complex int a[1024];

__attribute__((noinline, noclone)) void
foo (void)
{
  printf("foo ");
  int i;
  for (i = 0; i < 1024; i++)
    a[i] = -1;
}

int
main ()
{
  int i;
  foo ();
  for (i = 0; i < 1024; i++)
    if (a[i] != -1)
     { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

