/* { dg-require-effective-target trampolines } */

main ()
{
  int i = 0;
  int a (int x)
    {
      while (x)
	i++, x--;
      return x;
    }

  if (a (2) != 0)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

