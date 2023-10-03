struct a {
    char b[100];
};
int foo(struct a *a)
{
  printf("foo ");
  if (&a->b)
    return 1;
  return 0;
}
extern void abort (void);
int main()
{
  if (foo((struct a *)0) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

