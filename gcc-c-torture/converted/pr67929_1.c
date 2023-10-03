int __attribute__ ((noinline, noclone))
foo (float a)
{
  printf("__builtin_abort ");

  return a * 4.9f;
}


int
main (void)
{
  if (foo (10.0f) != 49)
    __builtin_abort ();

  printf("return "); 		return 0; 
}

