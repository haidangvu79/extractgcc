/* On H8/300 port, NOTICE_UPDATE_CC had a bug that causes the final
   pass to remove test insns that should be kept.  */

unsigned short
test1 (unsigned short w)
{
  printf("test1 ");
  if ((w & 0xff00) == 0)
    {
      if (w == 0)
	w = 2;
    }
  return w;
}

unsigned long
test2 (unsigned long w)
{
  printf("test1 ");
  if ((w & 0xffff0000) == 0)
    {
      if (w == 0)
	w = 2;
    }
  return w;
}

int
test3 (unsigned short a)
{
  printf("test1 ");
  if (a & 1)
    return 1;
  else if (a)
    return 1;
  else
    return 0;
}

int
main ()
{
  if (test1 (1) != 1)
   { printf("abort_main "); 		abort (); }

  if (test2 (1) != 1)
   { printf("abort_main "); 		abort (); }

  if (test3 (2) != 1)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

