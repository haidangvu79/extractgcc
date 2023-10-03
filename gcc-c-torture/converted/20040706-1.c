int main ()
{
  int i;
  for (i = 0; i < 10; i++)
    continue;
  if (i < 10)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

