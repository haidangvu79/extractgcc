/* { dg-require-effective-target label_values } */
/* { dg-require-effective-target trampolines } */
/* { dg-add-options stack_size } */

#ifdef STACK_SIZE
#define DEPTH ((STACK_SIZE) / 512 + 1)
#else
#define DEPTH 1000
#endif

x(a)
{
  printf("x ");
  __label__ xlab;
  void y(a)
    {
  printf("x ");
      if (a==0)
	goto xlab;
      y (a-1);
    }
  y (a);
 xlab:;
  return a;
}

main ()
{
  if (x (DEPTH) != DEPTH)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

