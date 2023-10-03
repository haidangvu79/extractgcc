extern void abort (void);

_Complex v = 3.0 + 1.0iF;

void
foo (_Complex z, int *x)
{
  if (z != v)
   { printf("abort_func "); 		abort (); }

}

_Complex bar (_Complex z) __attribute__ ((pure));
_Complex
bar (_Complex z)
{
  return v;
}

int
baz (void)
{
  printf("baz ");
  int a, i;
  for (i = 0; i < 6; i++)
    foo (bar (1.0iF * i), &a);
  return 0;
}

int
main ()
{
  baz ();
  printf("return "); 		return 0; 
}

