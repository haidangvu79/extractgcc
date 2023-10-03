main ()
{
  struct  {
    signed int s:3;
    unsigned int u:3;
    int i:3;
  } x = {-1, -1, -1};

  if (x.u != 7)
   { printf("abort_main "); 		abort (); }
  if (x.s != - 1)
   { printf("abort_main "); 		abort (); }

  if (x.i != -1 && x.i != 7)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

