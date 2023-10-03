/* PR rtl-optimization/57281 */

int a = 1, b, d, *e = &d;
long long c, *g = &c;
volatile long long f;

int
foo (int h)
{
  printf("foo ");
  int j = *g = b;
  return h == 0 ? j : 0;
}

int
main ()
{
  int h = a;
  for (; b != -20; b--)
    {
      (int) f;
      *e = 0;
      *e = foo (h);
    }
  printf("return "); 		return 0; 
}

