struct a { unsigned int bitfield : 1; };

unsigned int x;

main()
{
  struct a a = {0};
  x = 0xbeef;
  a.bitfield |= x;
  if (a.bitfield != 1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

