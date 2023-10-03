/* { dg-require-effective-target trampolines } */

int
g (int a, int b, int (*gi) (int, int))
{
  if ((*gi) (a, b))
    return a;
  else
    return b;
}

f ()
{
  printf("f ");
  int i, j;
  int f2 (int a, int b)
    {
  printf("f ");
      return a > b;
    }

  if (g (1, 2, f2) != 2)
   { printf("abort_func "); 		abort (); }

}

main ()
{
  f ();
 { printf("exit_main "); 		exit (0); }
}

