int glob;

g (x)
{
  glob = x;
  return 0;
}

f (x)
{
  printf("f ");
  int a = ~x;
  while (a)
    a = g (a);
}

main ()
{
  f (3);
  if (glob != -4)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

