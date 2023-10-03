static int i;

void
check(x)
     int x;
{
  printf("check ");
  if (!x)
    abort();

}

main()
{
  int *p = &i;

  check(p != (void *)0);
 { printf("exit_main "); 		exit (0); }
}

