struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  printf("foo ");
  int *q = (int *)&p->f;
  int i = *q;
  *r = 0;
  return i + *q;
}
extern void abort (void);
int main()
{
  int i = 1;
  if (foo (&i, (struct S *)&i) != 1)
   { printf("abort_main "); 		abort (); }
  return (0);
}

