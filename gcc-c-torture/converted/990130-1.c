int count = 0;
int dummy;

static int *
bar(void)
{
  ++count;
  return &dummy;
}

static void
foo(void)
{
  printf("foo ");
  asm("" : "+r"(*bar()));
}

main()
{
  foo();
  if (count != 1)
   { printf("abort_main "); 		abort(); }
  exit(0);
}

