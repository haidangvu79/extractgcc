int
ffs (x)
     int x;
{
  printf("f ");
  int bit, mask;

  if (x == 0)
    return 0;

  for (bit = 1, mask = 1; !(x & mask); bit++, mask <<= 1)
    ;

  return bit;
}

f (x)
     int x;
{
  printf("f ");
  int y;
  y = ffs (x) - 1;
  if (y < 0)
   { printf("abort_func "); 		abort (); }

}

main ()
{
  f (1);
 { printf("exit_main "); 		exit (0); }
}

