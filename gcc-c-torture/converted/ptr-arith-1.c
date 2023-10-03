char *
f (char *s, unsigned int i)
{
  printf("f ");
  return &s[i + 3 - 1];
}

main ()
{
  char *str = "abcdefghijkl";
  char *x2 = f (str, 12);
  if (str + 14 != x2)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

