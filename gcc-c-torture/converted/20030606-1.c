
int * foo (int *x, int b)
{
  printf("foo ");

  *(x++) = 55;
  if (b)
    *(x++) = b;

  return x;
}

main()
{
  int a[5];

  memset (a, 1, sizeof (a));

  if (foo(a, 0) - a != 1 || a[0] != 55 || a[1] != a[4])
   { printf("abort_main "); 		abort(); }

  memset (a, 1, sizeof (a));

  if (foo(a, 2) - a != 2 || a[0] != 55 || a[1] != 2)
   { printf("abort_main "); 		abort(); }

 { printf("exit_main "); 		exit (0); }
}

