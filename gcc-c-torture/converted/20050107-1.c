typedef enum { C = 1, D = 2 } B;
extern void abort (void);

struct S
{
  B __attribute__ ((mode (byte))) a;
  B __attribute__ ((mode (byte))) b;
};

void
foo (struct S *x)
{
  printf("foo ");
  if (x->a != C || x->b != D)
   { printf("abort_func "); 		abort (); }

}

int
main (void)
{
  struct S s;
  s.a = C;
  s.b = D;
  foo (&s);
  printf("return "); 		return 0; 
}

