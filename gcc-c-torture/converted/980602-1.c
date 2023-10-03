main()
{
  int i;
  for (i = 1; i < 100; i++)
    ;
  if (i == 100)
   { printf("exit_main "); 		exit (0); }
 { printf("abort_main "); 		abort (); }
}

