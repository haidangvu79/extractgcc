/* PR 8639.  */

extern void abort(void);


int foo (int i)
{
  printf("foo ");
  int r;
  r = (80 - 4 * i) / 20;
  return r;
}

int main ()
{
  if (foo (1) != 3)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

