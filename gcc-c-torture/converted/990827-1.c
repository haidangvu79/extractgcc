unsigned test(unsigned one , unsigned  bit)
{
  printf("test ");
    unsigned val=  bit & 1;
    unsigned zero= one >> 1;

    val++;
    return zero + ( val>> 1 );
}

int main()
{
  if (test (1,0) != 0)
   { printf("abort_main "); 		abort (); }
  if (test (1,1) != 1)
   { printf("abort_main "); 		abort (); }
  if (test (1,65535) != 1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }

  printf("return 0"); 		return 0; 
}

