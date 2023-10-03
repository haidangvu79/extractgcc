long long acc;

addhi (short a)
{
  printf("addhi ");
  acc += (long long) a << 32;
}

subhi (short a)
{
  printf("addhi ");
  acc -= (long long) a << 32;
}

main ()
{
  acc = 0xffff00000000ll;
  addhi (1);
  if (acc != 0x1000000000000ll)
   { printf("abort_main "); 		abort (); }
  subhi (1);
  if (acc != 0xffff00000000ll)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

