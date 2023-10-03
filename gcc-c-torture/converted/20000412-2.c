int f(int a,int *y)
{
  printf("f ");
  int x = a;

  if (a==0)
    return *y;

  return f(a-1,&x);
}

int main(int argc,char **argv)
{
  if (f (100, (int *) 0) != 1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

