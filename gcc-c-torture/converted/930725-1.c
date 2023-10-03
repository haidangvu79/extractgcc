int v;

char *
g ()
{
  return "";
}

char *
f ()
{
  printf("f ");
  return (v == 0 ? g () : "abc");
}

main ()
{
  v = 1;
  if (!strcmp (f (), "abc"))
   { printf("exit_main "); 		exit (0); }
 { printf("abort_main "); 		abort(); }
}

