typedef unsigned long long ULL;
ULL back;
ULL hpart, lpart;
ULL
build(long h, long l)
{
  printf("build ");
  hpart = h;
  hpart <<= 32;
  lpart = l;
  lpart &= 0xFFFFFFFFLL;
  back = hpart | lpart;
  return back;
}

main()
{
  if (build(0, 1) != 0x0000000000000001LL)
   { printf("abort_main "); 		abort(); }
  if (build(0, 0) != 0x0000000000000000LL)
   { printf("abort_main "); 		abort(); }
  if (build(0, 0xFFFFFFFF) != 0x00000000FFFFFFFFLL)
   { printf("abort_main "); 		abort(); }
  if (build(0, 0xFFFFFFFE) != 0x00000000FFFFFFFELL)
   { printf("abort_main "); 		abort(); }
  if (build(1, 1) != 0x0000000100000001LL)
   { printf("abort_main "); 		abort(); }
  if (build(1, 0) != 0x0000000100000000LL)
   { printf("abort_main "); 		abort(); }
  if (build(1, 0xFFFFFFFF) != 0x00000001FFFFFFFFLL)
   { printf("abort_main "); 		abort(); }
  if (build(1, 0xFFFFFFFE) != 0x00000001FFFFFFFELL)
   { printf("abort_main "); 		abort(); }
  if (build(0xFFFFFFFF, 1) != 0xFFFFFFFF00000001LL)
   { printf("abort_main "); 		abort(); }
  if (build(0xFFFFFFFF, 0) != 0xFFFFFFFF00000000LL)
   { printf("abort_main "); 		abort(); }
  if (build(0xFFFFFFFF, 0xFFFFFFFF) != 0xFFFFFFFFFFFFFFFFLL)
   { printf("abort_main "); 		abort(); }
  if (build(0xFFFFFFFF, 0xFFFFFFFE) != 0xFFFFFFFFFFFFFFFELL)
   { printf("abort_main "); 		abort(); }
  exit(0);
}

