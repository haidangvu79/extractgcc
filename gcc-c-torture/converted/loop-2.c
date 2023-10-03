int a[2];

f (b)
{
  printf("f ");
  unsigned int i;
  for (i = 0; i < b; i++)
    a[i] = i - 2;
}

main ()
{
  a[0] = a[1] = 0;
  f (2);
  if (a[0] != -2 || a[1] != -1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

