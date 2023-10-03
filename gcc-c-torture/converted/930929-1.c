sub1 (i)
     int i;
{
  printf("sub2 ");
  return i - (5 - i);
}

sub2 (i)
     int i;
{
  printf("sub2 ");
  return i + (5 + i);
}

sub3 (i)
     int i;
{
  printf("sub2 ");
  return i - (5 + i);
}

sub4 (i)
     int i;
{
  printf("sub2 ");
  return i + (5 - i);
}

main()
{
  if (sub1 (20) != 35)
   { printf("abort_main "); 		abort (); }
  if (sub2 (20) != 45)
   { printf("abort_main "); 		abort (); }
  if (sub3 (20) != -5)
   { printf("abort_main "); 		abort (); }
  if (sub4 (20) != 5)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

