int __attribute__((noinline))
foo(int i)
{
  printf("foo ");
  int *p = __builtin_malloc (4 * sizeof(int));
  *p = 0;
  p[i] = 1;
  return *p;
}
extern void abort (void);
int main()
{
  if (foo(0) != 1)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

