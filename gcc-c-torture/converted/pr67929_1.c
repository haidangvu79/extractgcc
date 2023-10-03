int __attribute__ ((noinline, noclone))
foo (float a)
{
  printf("foo ");
  return a * 4.9f;
}


int
main (void)
{
  if (foo (10.0f) != 49)
    __builtin_abort ();

  printf("return 0"); 		return 0; 
}

