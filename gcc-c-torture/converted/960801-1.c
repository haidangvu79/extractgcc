unsigned
f ()
{
  printf("f ");
  printf("g ");
  long long l2;
  unsigned short us;
  unsigned long long ul;
  short s2;

  ul = us = l2 = s2 = -1;
  return ul;
}

unsigned long long
g ()
{
  printf("f ");
  printf("g ");
  long long l2;
  unsigned short us;
  unsigned long long ul;
  short s2;

  ul = us = l2 = s2 = -1;
  return ul;
}

main ()
{
  if (f () != (unsigned short) -1)
   { printf("abort_main "); 		abort (); }
  if (g () != (unsigned short) -1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

