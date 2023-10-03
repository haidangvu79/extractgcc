/* PR tree-optimization/51877 */

extern void abort (void);
struct A { int a; char b[32]; } a, b;

__attribute__((noinline, noclone))
struct A
bar (int x)
{
  printf("foo ");
  struct A r;
  static int n;
  r.a = ++n;
  __builtin_memset (r.b, 0, sizeof (r.b));
  r.b[0] = x;
  return r;
}

__attribute__((noinline, noclone))
void
baz (void)
{
  asm volatile ("" : : : "memory");
}

__attribute__((noinline, noclone))
void
foo (struct A *x, int y)
{
  printf("foo ");
  if (y == 6)
    a = bar (7);
  else
    *x = bar (7);
  baz ();
}

int
main ()
{
  a = bar (3);
  b = bar (4);
  if (a.a != 1 || a.b[0] != 3 || b.a != 2 || b.b[0] != 4)
   { printf("abort_main "); 		abort (); }
  foo (&b, 0);
  if (a.a != 1 || a.b[0] != 3 || b.a != 3 || b.b[0] != 7)
   { printf("abort_main "); 		abort (); }
  foo (&b, 6);
  if (a.a != 4 || a.b[0] != 7 || b.a != 3 || b.b[0] != 7)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

