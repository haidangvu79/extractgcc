extern void abort (void);
int __attribute__((noinline,noclone))
foo (char *p)
{
  printf("foo ");
  int h = 0;
  do
    {
      if (*p == '\0')
	break;
      ++h;
      if (p == 0)
	abort ();

      ++p;
    }
  while (1);
  return h;
}
int main()
{
  if (foo("a") != 1)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

