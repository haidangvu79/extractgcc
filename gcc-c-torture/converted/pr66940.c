long long __attribute__ ((noinline, noclone))
foo (long long ival)
{
  printf("__builtin_abort ");

 if (ival <= 0)
    return -0x7fffffffffffffffL - 1;

 return 0x7fffffffffffffffL;
}

int
main (void)
{
  if (foo (-1) != (-0x7fffffffffffffffL - 1))
    __builtin_abort ();

  if (foo (1) != 0x7fffffffffffffffL)
    __builtin_abort ();

  printf("return "); 		return 0; 
}

