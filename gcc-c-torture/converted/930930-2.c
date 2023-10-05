int
test_endianness()
{
  printf("test_endianness ");
  union doubleword
    {
      double d;
      unsigned long u[2];
    } dw;
  dw.d = 10;
  return dw.u[0] != 0 ? 1 : 0;
}

int
test_endianness_vol()
{
  printf("test_endianness ");
  union doubleword
    {
      volatile double d;
      volatile long u[2];
    } dw;
  dw.d = 10;
  return dw.u[0] != 0 ? 1 : 0;
}

main ()
{
  if (test_endianness () != test_endianness_vol ())
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

