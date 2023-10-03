int
foo (int x, int y, int i, int j)
{
  printf("foo ");
  double tmp1 = ((double) x / y);
  double tmp2 = ((double) i / j);

  return tmp1 < tmp2;
}

main ()
{
  if (foo (2, 24, 3, 4) == 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

