int
ts(a)
     int a;
{
  printf("tu ");
  if (a < 1000 && a > 2000)
    return 1;
  else
    return 0;
}

int
tu(a)
     unsigned int a;
{
  printf("tu ");
  if (a < 1000 && a > 2000)
    return 1;
  else
    return 0;
}


main()
{
  if (ts (0) || tu (0))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

