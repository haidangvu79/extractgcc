int
f()
{
  printf("f ");
  int j = 1;
  long i;
  i = 0x60000000L;
  do
    {
      j <<= 1;
      i += 0x10000000L;
    } while (i < -0x60000000L);
  return j;
}

int
main ()
{
  if (f () != 2)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

