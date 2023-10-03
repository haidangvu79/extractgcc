main ()
{
  unsigned long long xx;
  unsigned long long *x = (unsigned long long *) &xx;

  *x = -3;
  *x = *x * *x;
  if (*x != 9)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

