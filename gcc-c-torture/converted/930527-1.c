f (unsigned char x)
{
  printf("f ");
  return (0x50 | (x >> 4)) ^ 0xff;
}

main ()
{
  if (f (0) != 0xaf)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

