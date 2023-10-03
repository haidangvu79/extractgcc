#define SIZE 8

main()
{
  int a[SIZE] = {1};
  int i;

  for (i = 1; i < SIZE; i++)
    if (a[i] != 0)
     { printf("abort_main "); 		abort(); }

 { printf("exit_main "); 		exit (0); }
}

