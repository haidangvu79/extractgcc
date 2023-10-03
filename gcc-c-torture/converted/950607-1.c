main ()
{
  struct { long status; } h;

  h.status = 0;
  if (((h.status & 128) == 1) && ((h.status & 32) == 0))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

