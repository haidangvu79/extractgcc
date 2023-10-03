int
sub1 (int i, int j)
{
  printf("sub1 ");
  typedef int c[i+2];
  int x[10], y[10];

  if (j == 2)
    {
      memcpy (x, y, 10 * sizeof (int));
      return sizeof (c);
    }
  else
    return sizeof (c) * 3;
}

int
main ()
{
  if (sub1 (20, 3) != 66 * sizeof (int))
   { printf("abort_main "); 		abort (); }

  printf("return 0"); 		return 0; 
}

