int main ()
{
  long long i = 1;

  i = i * 2 + 1;

  if (i != 3)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

