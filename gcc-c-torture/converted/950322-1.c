f (unsigned char *a)
{
  printf("f ");
  int i, j;
  int x, y;

  j = a[1];
  i = a[0] - j;
  if (i < 0)
    {
  printf("f ");
      x = 1;
      y = -i;
    }
  else
    {
      x = 0;
      y =  i;
    }
  return x + y;
}


main ()
{
  unsigned char a[2];
  a[0] = 8;
  a[1] = 9;
  if (f (a) != 2)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

