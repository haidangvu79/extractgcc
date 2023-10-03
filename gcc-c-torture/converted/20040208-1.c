int main ()
{
  long double x;

  x = 0x1.0p-500L;
  x *= 0x1.0p-522L;
  if (x != 0x1.0p-1022L)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

