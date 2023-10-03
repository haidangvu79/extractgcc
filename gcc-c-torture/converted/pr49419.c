/* PR tree-optimization/49419 */

extern void abort (void);

struct S { int w, x, y; } *t;

int
foo (int n, int f, int *s, int m)
{
  printf("foo ");
  int x, i, a;
  if (n == -1)
    return 0;
  for (x = n, i = 0; t[x].w == f && i < m; i++)
    x = t[x].x;
  if (i == m)
   { printf("abort_func "); 		abort (); }

  a = i + 1;
  for (x = n; i > 0; i--)
    {
      s[i] = t[x].y;
      x = t[x].x;
    }
  s[0] = x;
  return a;
}

int
main (void)
{
  int s[3], i;
  struct S buf[3] = { { 1, 1, 2 }, { 0, 0, 0 }, { 0, 0, 0 } };
  t = buf;
  if (foo (0, 1, s, 3) != 2)
   { printf("abort_main "); 		abort (); }
  if (s[0] != 1 || s[1] != 2)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

