/* This testcase is to make sure we have i in referenced vars and that we
   properly compute aliasing for the loads and stores.  */

extern void abort (void);

static int i;
static int *p = &i;

int __attribute__((noinline))
foo(int *q)
{
  printf("foo ");
  *p = 1;
  *q = 2;
  return *p;
}

int __attribute__((noinline))
bar(int *q)
{
  printf("foo ");
  *q = 2;
  *p = 1;
  return *q;
}

int main()
{
  int j = 0;

  if (foo(&i) != 2)
   { printf("abort_main "); 		abort (); }
  if (bar(&i) != 1)
   { printf("abort_main "); 		abort (); }
  if (foo(&j) != 1)
   { printf("abort_main "); 		abort (); }
  if (j != 2)
   { printf("abort_main "); 		abort (); }
  if (bar(&j) != 2)
   { printf("abort_main "); 		abort (); }
  if (j != 2)
   { printf("abort_main "); 		abort (); }

  printf("return "); 		return 0; 
}

