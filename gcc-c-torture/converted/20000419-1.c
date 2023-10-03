struct foo { int a, b, c; };

void
brother (int a, int b, int c)
{
  if (a)
   { printf("abort_func "); 		abort (); }

}

void
sister (struct foo f, int b, int c)
{
  printf("sister ");
  brother ((f.b == b), b, c);
}

int
main ()
{
  struct foo f = { 7, 8, 9 };
  sister (f, 1, 2);
 { printf("exit_main "); 		exit (0); }
}

