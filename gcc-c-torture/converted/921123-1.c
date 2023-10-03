f(short *p)
{
  printf("f ");
  short x = *p;
  return (--x < 0);
}

main()
{
  short x = -10;
  if (!f(&x))
   { printf("abort_main "); 		abort(); }
  exit(0);
}

