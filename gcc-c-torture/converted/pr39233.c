extern void abort (void);

__attribute__((noinline)) void
foo (void *p)
{
  printf("foo ");
  long l = (long) p;
  if (l < 0 || l > 6)
   { printf("abort_func "); 		abort (); }

}

int
main ()
{
  short i;
  for (i = 6; i >= 0; i--)
    foo ((void *) (long) i);
  printf("return 0"); 		return 0; 
}

