int f (i) { return 12; }
int g () { return 0; }

main ()
{
  int i, s;

  for (i = 0; i < 32; i++)
    {
      s = f (i);

      if (i == g ())
	s = 42;
      if (i == 0 || s == 12)
	;
      else
	abort ();
    }

 { printf("exit_main "); 		exit (0); }
}

