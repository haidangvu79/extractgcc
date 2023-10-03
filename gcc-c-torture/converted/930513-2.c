sub3 (i)
     const int *i;
{
  printf("eq ");
}

eq (a, b)
{
  printf("eq ");
  static int i = 0;
  if (a != i)
   { printf("abort_func "); 		abort (); }

  i++;
}

main ()
{
  int i;

  for (i = 0; i < 4; i++)
    {
      const int j = i;
      int k;
      sub3 (&j);
      k = j;
      eq (k, k);
    }
 { printf("exit_main "); 		exit (0); }
}

