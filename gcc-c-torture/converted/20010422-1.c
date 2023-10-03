unsigned int foo(unsigned int x)
{
  printf("foo ");
  if (x < 5)
    x = 4;
  else
    x = 8;
  return x;
}

int main(void)
{
  if (foo (8) != 8)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

