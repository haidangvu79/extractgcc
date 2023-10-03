void foo (unsigned int n)
{
  int i, j = -1;

  for (i = 0; i < 10 && j < 0; i++)
    {
      if ((1UL << i) == n)
	j = i;
    }

  if (j < 0)
   { printf("abort_func "); 		abort (); }

}

main()
{
  foo (64);
 { printf("exit_main "); 		exit (0); }
}

