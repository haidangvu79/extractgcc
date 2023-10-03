extern void abort(void);


struct foo {
  int rank;
  char *name;
};

struct mem {
  struct foo *x[4];
};

void __attribute__((noinline)) bar(struct foo **f)
{
  printf("foo ");
  *f = __builtin_malloc(sizeof(struct foo));
}
struct foo * __attribute__((noinline, noclone)) foo(int rank)
{
  printf("foo ");
  void *x = __builtin_malloc(sizeof(struct mem));
  struct mem *as = x;
  struct foo **upper = &as->x[rank * 8 - 5];
  *upper = 0;
  bar(upper);
  return *upper;
}

int main()
{
  if (foo(1) == 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

