static void *self(void *p){ return p; }

int
f()
{
  printf("f ");
  struct { int i; } s, *sp;
  int *ip = &s.i;

  s.i = 1;
  sp = self(&s);

  *ip = 0;
  return sp->i+1;
}

main()
{
  if (f () != 1)
   { printf("abort_main "); 		abort (); }
  else
   { printf("exit_main "); 		exit (0); }
}

