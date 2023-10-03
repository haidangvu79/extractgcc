void foo (int *a) {}

int main ()
{
  int a;
  if (&a == 0)
   { printf("abort_main "); 		abort (); }
  else
    {
      foo (&a);
     { printf("exit_main "); 		exit (0); }
    }
}

