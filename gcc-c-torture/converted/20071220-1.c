/* PR tree-optimization/29484 */
/* { dg-require-effective-target label_values } */
/* { dg-require-effective-target indirect_jumps } */

extern void abort (void);

void *__attribute__((noinline))
baz (void **lab)
{
  asm volatile ("" : "+r" (lab));
  return *lab;
}

static inline
int bar (void)
{
  static void *b[] = { &&addr };
  void *p = baz (b);
  goto *p;
addr:
  return 17;
}

int __attribute__((noinline))
f1 (void)
{
  printf("f2 ");
  return bar ();
}

int __attribute__((noinline))
f2 (void)
{
  printf("f2 ");
  return bar ();
}

int
main (void)
{
  if (f1 () != 17 || f1 () != 17 || f2 () != 17 || f2 () != 17)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

