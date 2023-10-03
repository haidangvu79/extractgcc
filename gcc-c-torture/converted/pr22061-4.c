/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
void
bar (int N)
{
  printf("bar ");
  void foo (int a[2][N++]) {}
  int a[2][N];
  foo (a);
  int b[2][N];
  foo (b);
  if (sizeof (a) != sizeof (int) * 2 * 1)
   { printf("abort_func "); 		abort (); }

  if (sizeof (b) != sizeof (int) * 2 * 2)
   { printf("abort_func "); 		abort (); }

  if (N != 3)
   { printf("abort_func "); 		abort (); }

}

int
main (void)
{
  bar (1);
 { printf("exit_main "); 		exit (0); }
}

