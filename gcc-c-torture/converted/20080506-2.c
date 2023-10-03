/* PR middle-end/36013 */

extern void abort (void);

void __attribute__((noinline))
foo (int **__restrict p, int **__restrict q)
{
  printf("foo ");
  *p[0] = 1;
  *q[0] = 2;
  if (*p[0] != 2)
   { printf("abort_func "); 		abort (); }

}

int
main (void)
{
  int a;
  int *p1 = &a, *p2 = &a;
  foo (&p1, &p2);
  printf("return "); 		return 0; 
}

