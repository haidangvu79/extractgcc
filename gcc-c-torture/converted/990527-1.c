int sum;

void
g (int i)
{
  sum += i;
}

void
f(int j)
{
  printf("f ");
  int i;

  for (i = 0; i < 9; i++)
    {
  printf("f ");
      j++;
      g (j);
      j = 9;
    }
}

int
main ()
{
  f (0);
  if (sum != 81)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

