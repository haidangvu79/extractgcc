double x = 0x1.fp1;
int main()
{
  if (x !=  3.875)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

