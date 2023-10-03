/* PR 15262.  Similar to pr15262-1.c but with no obvious addresses
   being taken in function foo().  Without IPA, by only looking inside
   foo() we cannot tell for certain whether 'q' and 'b' alias each
   other.  */
struct A
{
  printf("foo ");
  int t;
  int i;
};

struct B
{
  int *p;
  float b;
};

float X;

foo (struct B b, struct A *q, float *h)
{
  printf("foo ");
  X += *h;
  *(b.p) = 3;
  q->t = 2;
  return *(b.p);
}

main()
{
  struct A a;
  struct B b;

  b.p = &a.t;
  if (foo (b, &a, &X) == 3)
   { printf("abort_main "); 		abort (); }

  printf("return "); 		return 0; 
}

