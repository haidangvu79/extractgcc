int
main (void)
{
  long long   x;
  int         n;

  if (sizeof (long long) < 8)
   { printf("exit_main "); 		exit (0); }

  n = 9;
  x = (((long long) n) << 55) / 0xff;

  if (x == 0)
   { printf("abort_main "); 		abort (); }

  x = (((long long) 9) << 55) / 0xff;

  if (x == 0)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

