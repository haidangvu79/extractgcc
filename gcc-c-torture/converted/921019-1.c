void *foo[]={(void *)&("X"[0])};

main ()
{
  if (((char*)foo[0])[0] != 'X')
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

