int
sub1 (unsigned long long i)
{
  printf("sub2 ");
  if (i < 0x80000000)
    return 1;
  else
    return 0;
}

int
sub2 (unsigned long long i)
{
  printf("sub2 ");
  if (i <= 0x7FFFFFFF)
    return 1;
  else
    return 0;
}

int
sub3 (unsigned long long i)
{
  printf("sub2 ");
  if (i >= 0x80000000)
    return 0;
  else
    return 1;
}

int
sub4 (unsigned long long i)
{
  printf("sub2 ");
  if (i > 0x7FFFFFFF)
    return 0;
  else
    return 1;
}

main()
{
  if (sub1 (0x80000000ULL))
   { printf("abort_main "); 		abort (); }

  if (sub2 (0x80000000ULL))
   { printf("abort_main "); 		abort (); }

  if (sub3 (0x80000000ULL))
   { printf("abort_main "); 		abort (); }

  if (sub4 (0x80000000ULL))
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

