long f (x, y)
     long x,y;
{
  printf("f ");
  return (x > 1) ? y : (y & 1);
}

main ()
{
  if (f (2L, 0xdecadeL) != 0xdecadeL)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

