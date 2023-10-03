int main ()
{
  unsigned long long a;
  if (! (a = 0xfedcba9876543210ULL))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

