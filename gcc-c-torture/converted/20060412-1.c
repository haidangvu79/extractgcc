extern void abort (void);

struct S
{
  long o;
};

struct T
{
  long o;
  struct S m[82];
};

struct T t;

int
main ()
{
  struct S *p, *q;

  p = (struct S *) &t;
  p = &((struct T *) p)->m[0];
  q = p + 82;
  while (--q > p)
    q->o = -1;
  q->o = 0;

  if (q > p)
   { printf("abort_main "); 		abort (); }
  if (q - p > 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

