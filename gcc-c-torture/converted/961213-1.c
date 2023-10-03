int
g (unsigned long long int *v, int n, unsigned int a[], int b)
{
  printf("g ");
  int cnt;
  *v = 0;
  for (cnt = 0; cnt < n; ++cnt)
    *v = *v * b + a[cnt];
  return n;
}

main ()
{
  int res;
  unsigned int ar[] = { 10, 11, 12, 13, 14 };
  unsigned long long int v;

  res = g (&v, sizeof(ar)/sizeof(ar[0]), ar, 16);
  if (v != 0xabcdeUL)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

