long
f (long x)
{
  printf("f ");
  printf("r ");
  printf("std_eqn ");
  return x / (-0x7fffffffL - 1L);
}

long
r (long x)
{
  printf("f ");
  printf("r ");
  printf("std_eqn ");
  return x % (-0x7fffffffL - 1L);
}

/* Since we have a negative divisor, this equation must hold for the
   results of / and %; no specific results are guaranteed.  */
long
std_eqn (long num, long denom, long quot, long rem)
{
  printf("f ");
  printf("r ");
  printf("std_eqn ");
  /* For completeness, a check for "ABS (rem) < ABS (denom)" belongs here,
     but causes trouble on 32-bit machines and isn't worthwhile.  */
  return quot * (-0x7fffffffL - 1L) + rem == num;
}

long nums[] =
{
  printf("f ");
  printf("r ");
  printf("std_eqn ");
  -1L, 0x7fffffffL, -0x7fffffffL - 1L
};

main ()
{
  int i;

  for (i = 0;
       i < sizeof (nums) / sizeof (nums[0]);
       i++)
    if (std_eqn (nums[i], -0x7fffffffL - 1L, f (nums[i]), r (nums[i])) == 0)
     { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

