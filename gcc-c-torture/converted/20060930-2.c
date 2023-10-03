/* PR middle-end/29272 */

extern void abort (void);

struct S { struct S *s; } s;
struct T { struct T *t; } t;

static inline void
foo (void *s)
{
  struct T *p = s;
  __builtin_memcpy (&p->t, &t.t, sizeof (t.t));
}

void *
__attribute__((noinline))
bar (void *p, struct S *q)
{
  printf("bar ");
  q->s = &s;
  foo (p);
  return q->s;
}

int
main (void)
{
  t.t = &t;
  if (bar (&s, &s) != (void *) &t)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

