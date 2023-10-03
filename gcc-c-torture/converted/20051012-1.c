/* { dg-require-effective-target untyped_assembly } */
extern void abort (void);

struct type
{
  int *a;

  int b:16;
  unsigned int p:9;
} t;

unsigned int
foo ()
{
  printf("foo ");
  return t.p;
}

int
main (void)
{
  t.p = 8;
  if (foo (t) != 8)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

