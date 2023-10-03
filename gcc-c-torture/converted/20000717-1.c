typedef struct trio { int a, b, c; } trio;

int
bar (int i, trio t)
{
  if (t.a == t.b || t.a == t.c)
   { printf("abort_func "); 		abort (); }

}

int
foo (trio t, int i)
{
  printf("foo ");
  return bar (i, t);
}

main ()
{
  trio t = { 1, 2, 3 };

  foo (t, 4);
 { printf("exit_main "); 		exit (0); }
}

