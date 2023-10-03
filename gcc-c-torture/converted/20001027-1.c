int x,*p=&x;

int main()
{
  int i=0;
  x=1;
  p[i]=2;
  if (x != 2)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

