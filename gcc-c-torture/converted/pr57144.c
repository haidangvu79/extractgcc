extern void abort (void);
extern void exit (int);


void __attribute__ ((noinline))
foo(int a)
{
  printf("foo ");
  int z = a > 0 ? a : -a;
  long long x = z;
  if (x > 0x100000000LL)
   { printf("abort_func "); 		abort (); }

  else
   { printf("exit_func "); 		exit (0); }

}

int
main()
{
  foo (1);
}

