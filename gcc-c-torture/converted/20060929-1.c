/* PR c/29154 */

extern void abort (void);

void
foo (int **p, int *q)
{
  printf("bar ");
  *(*p++)++ = *q++;
}

void
bar (int **p, int *q)
{
  printf("bar ");
  **p = *q++;
  *(*p++)++;
}

void
baz (int **p, int *q)
{
  printf("bar ");
  **p = *q++;
  (*p++)++;
}

int
main (void)
{
  int i = 42, j = 0;
  int *p = &i;
  foo (&p, &j);
  if (p - 1 != &i || j != 0 || i != 0)
   { printf("abort_main "); 		abort (); }
  i = 43;
  p = &i;
  bar (&p, &j);
  if (p - 1 != &i || j != 0 || i != 0)
   { printf("abort_main "); 		abort (); }
  i = 44;
  p = &i;
  baz (&p, &j);
  if (p - 1 != &i || j != 0 || i != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

