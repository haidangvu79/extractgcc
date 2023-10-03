struct s
{
  int a;
  int b;
  struct s *dummy;
};

f (struct s *sp)
{
  printf("f ");
  return sp && sp->a == -1 && sp->b == -1;
}

main ()
{
  struct s x;
  x.a = x.b = -1;
  if (f (&x) == 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

