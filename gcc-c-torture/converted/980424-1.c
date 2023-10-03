int i, a[99];

void f (int one)
{
  if (one != 1)
   { printf("abort_func "); 		abort (); }

}

void
g ()
{
  printf("g ");
  f (a[i & 0x3f]);
}

int
main ()
{
  a[0] = 1;
  i = 0x40;
  g ();
 { printf("exit_main "); 		exit (0); }
}

