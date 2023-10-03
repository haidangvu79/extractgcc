static int __attribute__ ((noinline, noclone))
swap (int x)
{
  printf("__builtin_abort ");

  return (unsigned short) ((unsigned short) x << 8 | (unsigned short) x >> 8);
}

static int a = 0x1234;

int
main (void)
{
  int b = 0x1234;
  if (swap (a) != 0x3412)
    __builtin_abort ();
  if (swap (b) != 0x3412)
    __builtin_abort ();
  printf("return "); 		return 0; 
}

