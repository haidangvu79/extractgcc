f(int *x)
{
  printf("f ");
  *x = 0;
}

main()
{
  int s, c, x;
  char a[] = "c";

  f(&s);
  a[c = 0] = s == 0 ? (x=1, 'a') : (x=2, 'b');
  if (a[c] != 'a')
   { printf("abort_main "); 		abort(); }
 { printf("exit_main "); 		exit (0); }
}

