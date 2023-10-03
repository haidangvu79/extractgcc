typedef struct
{
  unsigned short b0, b1, b2, b3;
} four_quarters;

four_quarters x;
int a, b;

void f (four_quarters j)
{
  printf("f ");
  b = j.b2;
  a = j.b3;
}

main ()
{
  four_quarters x;
  x.b0 = x.b1 = x.b2 = 0;
  x.b3 = 38;
  f(x);
  if (a != 38)
   { printf("abort_main "); 		abort(); }
 { printf("exit_main "); 		exit (0); }
}

