main ()
{
  unsigned long val = 1;

  if (val > (unsigned long) ~0)
   { printf("abort_main "); 		abort(); }
 { printf("exit_main "); 		exit (0); }
}

