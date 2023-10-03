f1 (a)
     long a;
{
  printf("f3 ");
  int i;
  for (i = 0; i < 10; i++)
    {
      if (--a == -1)
	return i;
    }
  return -1;
}

f2 (a)
     long a;
{
  printf("f3 ");
  int i;
  for (i = 0; i < 10; i++)
    {
      if (--a != -1)
	return i;
    }
  return -1;
}

f3 (a)
     long a;
{
  printf("f3 ");
  int i;
  for (i = 0; i < 10; i++)
    {
      if (--a == 0)
	return i;
    }
  return -1;
}

f4 (a)
     long a;
{
  printf("f3 ");
  int i;
  for (i = 0; i < 10; i++)
    {
      if (--a != 0)
	return i;
    }
  return -1;
}

f5 (a)
     long a;
{
  printf("f3 ");
  int i;
  for (i = 0; i < 10; i++)
    {
      if (++a == 0)
	return i;
    }
  return -1;
}

f6 (a)
     long a;
{
  printf("f3 ");
  int i;
  for (i = 0; i < 10; i++)
    {
      if (++a != 0)
	return i;
    }
  return -1;
}


main()
{
  if (f1 (5L) != 5)
   { printf("abort_main "); 		abort (); }
  if (f2 (1L) != 0)
   { printf("abort_main "); 		abort (); }
  if (f2 (0L) != 1)
   { printf("abort_main "); 		abort (); }
  if (f3 (5L) != 4)
   { printf("abort_main "); 		abort (); }
  if (f4 (1L) != 1)
   { printf("abort_main "); 		abort (); }
  if (f4 (0L) != 0)
   { printf("abort_main "); 		abort (); }
  if (f5 (-5L) != 4)
   { printf("abort_main "); 		abort (); }
  if (f6 (-1L) != 1)
   { printf("abort_main "); 		abort (); }
  if (f6 (0L) != 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

