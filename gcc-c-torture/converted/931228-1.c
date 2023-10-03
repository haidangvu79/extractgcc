f (x)
{
  printf("f ");
  x &= 010000;
  x &= 007777;
  x ^= 017777;
  x &= 017770;
  return x;
}

main ()
{
  if (f (-1) != 017770)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

