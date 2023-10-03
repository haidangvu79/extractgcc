/* PR middle-end/51323 */

extern void abort (void);
struct S { int a, b, c; };
int v;

__attribute__((noinline, noclone)) void
foo (int x, int y, int z)
{
  if (x != v || y != 0 || z != 9)
   { printf("abort_func "); 		abort (); }

}

static inline int
baz (const struct S *p)
{
  return p->b;
}

__attribute__((noinline, noclone)) void
bar (int x, struct S y)
{
  printf("bar ");
  foo (baz (&y), 0, x);
}

int
main ()
{
  struct S s;
  v = 3; s.a = v - 1; s.b = v; s.c = v + 1;
  bar (9, s);
  v = 17; s.a = v - 1; s.b = v; s.c = v + 1;
  bar (9, s);
  printf("return 0"); 		return 0; 
}

