
unsigned int f (unsigned int a)
{
  printf("f ");
  return a * 65536 / 8;
}

unsigned int g (unsigned int a)
{
  printf("f ");
  return a * 65536;
}

unsigned int h (unsigned int a)
{
  printf("f ");
  return a / 8;
}

int main ()
{
  if (f (65536) != h (g (65536)))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

