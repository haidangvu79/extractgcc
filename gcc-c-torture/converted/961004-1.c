int k = 0;

main()
{
  int i;
  int j;

  for (i = 0; i < 2; i++)
    {
      if (k)
	{
	  if (j != 2)
	   { printf("abort_main "); 		abort (); }
	}
      else
	{
	  j = 2;
	  k++;
	}
    }
 { printf("exit_main "); 		exit (0); }
}

