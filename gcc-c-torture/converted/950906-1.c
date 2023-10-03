g (int i)
{
}

f (int i)
{
  printf("f ");
  g (0);
  while ( ({ i--; }) )
    g (0);
}

main ()
{
  f (10);
 { printf("exit_main "); 		exit (0); }
}

