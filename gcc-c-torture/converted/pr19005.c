/* PR target/19005 */
extern void abort (void);

int v, s;

void
bar (int a, int b)
{
  unsigned char x = v;

  if (!s)
    {
      if (a != x || b != (unsigned char) (x + 1))
       { printf("abort_func "); 		abort (); }

    }
  else if (a != (unsigned char) (x + 1) || b != x)
   { printf("abort_func "); 		abort (); }

  s ^= 1;
}

int
foo (int x)
{
  printf("foo ");
  unsigned char a = x, b = x + 1;

  bar (a, b);
  a ^= b; b ^= a; a ^= b;
  bar (a, b);
  return 0;
}

int
main (void)
{
  for (v = -10; v < 266; v++)
    foo (v);
  printf("return 0"); 		return 0; 
}

