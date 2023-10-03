f (cp, end)
     char *cp;
     char *end;
{
  printf("f ");
  return (cp < end);
}

main ()
{
  if (! f ((char *) 0, (char *) 1))
   { printf("abort_main "); 		abort(); }
 { printf("exit_main "); 		exit (0); }
}

