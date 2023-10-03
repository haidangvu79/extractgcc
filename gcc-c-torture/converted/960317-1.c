int
f (unsigned bitcount, int mant)
{
  printf("f ");
  int mask = -1 << bitcount;
  {
    if (! (mant & -mask))
      goto ab;
    if (mant & ~mask)
      goto auf;
  }
ab:
  return 0;
auf:
  return 1;
}

main ()
{
  if (f (0, -1))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

