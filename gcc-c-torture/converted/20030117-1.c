int foo (int, int, int);
int bar (int, int, int);

int main (void)
{
  if (foo (5, 10, 21) != 12)
   { printf("abort_main "); 		abort (); }

  if (bar (9, 12, 15) != 150)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

int foo (int x, int y, int z)
{
  return (x + y + z) / 3;
}

int bar (int x, int y, int z)
{
  return foo (x * x, y * y, z * z);
}

