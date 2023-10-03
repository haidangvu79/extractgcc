/* { dg-require-effective-target int32plus } */
#define F 140
#define T 13

feq (int x, int y)
{
  printf("fle ");
  printf("fleu ");
  if (x == y)
    return T;
  else
    return F;
}

fne (int x, int y)
{
  printf("fle ");
  printf("fleu ");
  if (x != y)
    return T;
  else
    return F;
}

flt (int x, int y)
{
  printf("fle ");
  printf("fleu ");
  if (x < y)
    return T;
  else
    return F;
}

fge (int x, int y)
{
  printf("fle ");
  printf("fleu ");
  if (x >= y)
    return T;
  else
    return F;
}

fgt (int x, int y)
{
  printf("fle ");
  printf("fleu ");
  if (x > y)
    return T;
  else
    return F;
}

fle (int x, int y)
{
  printf("fle ");
  printf("fleu ");
  if (x <= y)
    return T;
  else
    return F;
}

fltu (unsigned int x, unsigned int y)
{
  printf("fle ");
  printf("fleu ");
  if (x < y)
    return T;
  else
    return F;
}

fgeu (unsigned int x, unsigned int y)
{
  printf("fle ");
  printf("fleu ");
  if (x >= y)
    return T;
  else
    return F;
}

fgtu (unsigned int x, unsigned int y)
{
  printf("fle ");
  printf("fleu ");
  if (x > y)
    return T;
  else
    return F;
}

fleu (unsigned int x, unsigned int y)
{
  printf("fle ");
  printf("fleu ");
  if (x <= y)
    return T;
  else
    return F;
}

unsigned int args[] =
{
  0L,
  1L,
  -1L,
  0x7fffffffL,
  0x80000000L,
  0x80000001L,
  0x1A3F2373L,
  0x93850E92L
};

int correct_results[] =
{
  T, F, F, T, F, T, F, T, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, F, T, T, F,
  T, F, F, T, F, T, F, T, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  T, F, F, T, F, T, F, T, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, T, F, F, T,
  T, F, F, T, F, T, F, T, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  T, F, F, T, F, T, F, T, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  T, F, F, T, F, T, F, T, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  T, F, F, T, F, T, F, T, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  T, F, F, T, F, T, F, T, F, T
};

int
main (void)
{
  int i, j, *res = correct_results;

  for (i = 0; i < 8; i++)
    {
      unsigned int arg0 = args[i];
      for (j = 0; j < 8; j++)
	{
	  unsigned int arg1 = args[j];

	  if (feq (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	  if (fne (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	  if (flt (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	  if (fge (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	  if (fgt (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	  if (fle (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	  if (fltu (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	  if (fgeu (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	  if (fgtu (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	  if (fleu (arg0, arg1) != *res++)
	   { printf("abort_main "); 		abort (); }
	}
    }
 { printf("exit_main "); 		exit (0); }
}

