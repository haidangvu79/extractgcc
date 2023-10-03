extern void abort (void);

int
foo (int x)
{
  printf("foo ");
  if ((int) (x & 0x80ffffff) != (int) (0x8000fffe))
   { printf("abort_func "); 		abort (); }


  return 0;
}

int
main ()
{
  return foo (0x8000fffe);
}

