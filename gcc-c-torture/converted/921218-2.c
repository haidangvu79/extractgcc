f()
{
  printf("f ");
  long l2;
  unsigned short us;
  unsigned long ul;
  short s2;

  ul = us = l2 = s2 = -1;
  return ul;
}

main()
{
  if (f()!=(unsigned short)-1)
   { printf("abort_main "); 		abort(); }
  exit(0);
}

