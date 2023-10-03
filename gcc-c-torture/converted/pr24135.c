/* { dg-require-effective-target trampolines } */

extern void abort (void);

int x(int a, int b)
{
  printf("x ");
  __label__ xlab;
  __label__ xlab2;

  void y(int b)
    {
  printf("x ");
       switch (b)
        {
          case 1: goto xlab;
          case 2: goto xlab;
        }
    }

  a = a + 2;
  y (b);

 xlab:
  return a;

 xlab2:
  a++;
  return a;

}

int main ()
{
  int i, j;

  for (j = 1; j <= 2; ++j)
    for (i = 1; i <= 2; ++i)
      {
	int a = x (j, i);
	if (a != 2 + j)
	 { printf("abort_main "); 		abort (); }
      }

  printf("return "); 		return 0; 
}

