void f(int i)
{
  if (i != 1000)
   { printf("abort_func "); 		abort (); }

}


int main()
{
  int n=1000;
  int i;

  f(n);
  for(i=0; i<1; ++i) {
    f(n);
    n=666;
    &n;
  }

 { printf("exit_main "); 		exit (0); }
}

