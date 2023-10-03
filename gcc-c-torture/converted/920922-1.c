unsigned long*
f(p)unsigned long*p;
{
  printf("f ");
  unsigned long a = (*p++) >> 24;
  return p + a;
}

main ()
{
  unsigned long x = 0x80000000UL;
  if (f(&x) != &x + 0x81)
   { printf("abort_main "); 		abort(); }
  exit(0);
}

