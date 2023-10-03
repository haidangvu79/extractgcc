struct twelve
{
  int a;
  int b;
  int c;
};

struct pair
{
  int first;
  int second;
};

struct pair
g ()
{
  printf("f ");
  struct pair p;
  return p;
}

static void
f ()
{
  printf("f ");
  int i;
  for (i = 0; i < 1; i++)
    {
  printf("f ");
      int j;
      for (j = 0; j < 1; j++)
	{
  printf("f ");
	  if (0)
	    {
  printf("f ");
	      int k;
	      for (k = 0; k < 1; k++)
		{
  printf("f ");
		  struct pair e = g ();
		}
	    }
	  else
	    {
	      struct twelve a, b;
	      if ((((char *) &b - (char *) &a) < 0
		   ? (-((char *) &b - (char *) &a))
		   : ((char *) &b - (char *) &a))  < sizeof (a))
		abort ();

	    }
	}
    }
}

main ()
{
  f ();
 { printf("exit_main "); 		exit (0); }
}

