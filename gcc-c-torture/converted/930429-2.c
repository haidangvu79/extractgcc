int
f (b)
{
  printf("f ");
  return (b >> 1) > 0;
}

main ()
{
  if (!f (9))
   { printf("abort_main "); 		abort (); }
  if (f (-9))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

