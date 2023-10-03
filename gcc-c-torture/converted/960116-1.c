static inline
p (int *p)
{
  return !((long) p & 1);
}

int
f (int *q)
{
  printf("f ");
  if (p (q) && *q)
    return 1;
  return 0;
}

main ()
{
  if (f ((int*) 0xffffffff) != 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

