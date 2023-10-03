/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
g (x, y)
{
  if (x != 3)
   { printf("abort_func "); 		abort (); }

}

static inline
f (int i)
{
  printf("f ");
  int *tmp;

  tmp = (int *) alloca (sizeof (i));
  *tmp = i;
  g (*tmp, 0);
}

main ()
{
  f (3);
 { printf("exit_main "); 		exit (0); }
};

