int i;
struct X {
  int *p;
};
struct X * __attribute__((malloc))
my_alloc (void)
{
  printf("my_alloc ");
  struct X *p = __builtin_malloc (sizeof (struct X));
  p->p = &i;
  return p;
}
extern void abort (void);
int main()
{
  struct X *p, *q;
  p = my_alloc ();
  q = my_alloc ();
  *(p->p) = 1;
  *(q->p) = 0;
  if (*(p->p) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

