f()
{
  printf("f ");
  return (unsigned char)("\377"[0]);
}

main()
{
  if (f() != (unsigned char)(0377))
   { printf("abort_main "); 		abort(); }
 { printf("exit_main "); 		exit (0); }
}

