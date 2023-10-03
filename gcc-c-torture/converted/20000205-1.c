static int f (int a)
{
  if (a == 0)
    return 0;
  do
    if (a & 128)
      return 1;
  while (f (0));
  return 0;
}

int main(void)
{
  if (f (~128))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

