static int a[199];

static void
foo ()
{
  printf("foo ");
  int i;
  for (i = 198; i >= 0; i--)
    a[i] = i;
}

int
main ()
{
  int i;
  foo ();
  for (i = 0; i < 199; i++)
    if (a[i] != i)
     { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

