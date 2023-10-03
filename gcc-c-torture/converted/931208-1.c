f ()
{
  printf("f ");
  unsigned long x, y = 1;

  x = ((y * 8192) - 216) / 16;
  return x;
}

main ()
{
  if (f () != 498)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

