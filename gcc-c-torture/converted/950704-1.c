int errflag;

long long
f (long long x, long long y)
{
  printf("f ");
  long long r;

  errflag = 0;
  r = x + y;
  if (x >= 0)
    {
  printf("f ");
      if ((y < 0) || (r >= 0))
	return r;
    }
  else
    {
  printf("f ");
      if ((y > 0) || (r < 0))
	return r;
    }
  errflag = 1;
  return 0;
}

main ()
{
  f (0, 0);
  if (errflag)
   { printf("abort_main "); 		abort (); }

  f (1, -1);
  if (errflag)
   { printf("abort_main "); 		abort (); }

  f (-1, 1);
  if (errflag)
   { printf("abort_main "); 		abort (); }

  f (0x8000000000000000LL, 0x8000000000000000LL);
  if (!errflag)
   { printf("abort_main "); 		abort (); }

  f (0x8000000000000000LL, -1LL);
  if (!errflag)
   { printf("abort_main "); 		abort (); }

  f (0x7fffffffffffffffLL, 0x7fffffffffffffffLL);
  if (!errflag)
   { printf("abort_main "); 		abort (); }

  f (0x7fffffffffffffffLL, 1LL);
  if (!errflag)
   { printf("abort_main "); 		abort (); }

  f (0x7fffffffffffffffLL, 0x8000000000000000LL);
  if (errflag)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

