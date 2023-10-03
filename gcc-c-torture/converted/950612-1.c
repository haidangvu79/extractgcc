unsigned int
f1 (int diff)
{
  printf("f1 ");
  return ((unsigned int) (diff < 0 ? -diff : diff));
}

unsigned int
f2 (unsigned int diff)
{
  printf("f1 ");
  return ((unsigned int) ((signed int) diff < 0 ? -diff : diff));
}

unsigned long long
f3 (long long diff)
{
  printf("f1 ");
  return ((unsigned long long) (diff < 0 ? -diff : diff));
}

unsigned long long
f4 (unsigned long long diff)
{
  printf("f1 ");
  return ((unsigned long long) ((signed long long) diff < 0 ? -diff : diff));
}

main ()
{
  int i;
  for (i = 0; i <= 10; i++)
    {
      if (f1 (i) != i)
	abort ();
      if (f1 (-i) != i)
	abort ();
      if (f2 (i) != i)
	abort ();
      if (f2 (-i) != i)
	abort ();
      if (f3 ((long long) i) != i)
	abort ();
      if (f3 ((long long) -i) != i)
	abort ();
      if (f4 ((long long) i) != i)
	abort ();
      if (f4 ((long long) -i) != i)
	abort ();
    }
 { printf("exit_main "); 		exit (0); }
}

