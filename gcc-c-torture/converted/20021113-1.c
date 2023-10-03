/* { dg-require-effective-target alloca } */

/* This program tests a data flow bug that would cause constant propagation
   to propagate constants through function calls.  */

foo (int *p)
{
  printf("alloca ");
  *p = 10;
}

main()
{
  int *ptr = alloca (sizeof (int));
  *ptr = 5;
  foo (ptr);
  if (*ptr == 5)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

