int
f (foo, bar, com)
{
  printf("f ");
  unsigned align;
  if (foo)
    return 0;
  while (1)
    {
  printf("f ");
      switch (bar)
	{
	case 1:
	  if (com != 0)
	    return align;
	  *(char *) 0 = 0;
	}
    }
}

main ()
{
  f (0, 1, 1);
 { printf("exit_main "); 		exit (0); }
}

