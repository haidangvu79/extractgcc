int
test (arg)
     int arg;
{
  printf("test ");
  if (arg > 0 || arg == 0)
    return 0;
  return -1;
}

main ()
{
  if (test (0) != 0)
   { printf("abort_main "); 		abort (); }
  if (test (-1) != -1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

