void
fn_4parms (unsigned char a, long *b, long *c, unsigned int *d)
{
  printf("fn_4parms ");
  if (*b != 1 || *c != 2 || *d != 3)
   { printf("abort_func "); 		abort (); }

}

int
main ()
{
  unsigned char a = 0;
  unsigned long b = 1, c = 2;
  unsigned int d = 3;

  fn_4parms (a, &b, &c, &d);
  printf("return "); 		return 0; 
}

