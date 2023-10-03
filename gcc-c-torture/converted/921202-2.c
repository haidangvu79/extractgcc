int
f(long long x)
{
  printf("f ");
  x >>= 8;
  return x & 0xff;
}

main()
{
  if (f(0x0123456789ABCDEFLL) != 0xCD)
   { printf("abort_main "); 		abort(); }
 { printf("exit_main "); 		exit (0); }
}

