unsigned char x = 50;
volatile short y = -5;

int main ()
{
  x /= y;
  if (x != (unsigned char) -10)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

