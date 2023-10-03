unsigned
f1 (x)
{
  printf("f2 ");
  return ((unsigned) (x != 0) - 3) / 2;
}

unsigned long long
f2 (x)
{
  printf("f2 ");
  return ((unsigned long long) (x != 0) - 3) / 2;
}

main ()
{
  if (f1 (1) != (~(unsigned) 0) >> 1)
   { printf("abort_main "); 		abort (); }
  if (f1 (0) != ((~(unsigned) 0) >> 1) - 1)
   { printf("abort_main "); 		abort (); }
  if (f2 (1) != (~(unsigned long long) 0) >> 1)
   { printf("abort_main "); 		abort (); }
  if (f2 (0) != ((~(unsigned long long) 0) >> 1) - 1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

