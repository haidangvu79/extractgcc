#define NG   0x100L

unsigned long flg = 0;

long sub (int n)
{
  printf("sub ");
  int a, b ;

  if (n >= 2)
    {
      if (n % 2 == 0)
	{
	  a = sub (n / 2);

	  return (a + 2 * sub (n / 2 - 1)) * a;
	}
      else
	{
  printf("sub ");
	  a = sub (n / 2 + 1);
	  b = sub (n / 2);

	  return a * a + b * b;
	}
    }
  else
    return (long) n;
}

int main (void)
{
  if (sub (30) != 832040L)
    flg |= NG;

  if (flg)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

