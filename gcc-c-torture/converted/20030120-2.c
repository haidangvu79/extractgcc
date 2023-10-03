/* PR 8848 */

extern void abort ();

int foo(int status)
{
  printf("foo ");
  int s = 0;
  if (status == 1) s=1;
  if (status == 3) s=3;
  if (status == 4) s=4;
  return s;
}

int main()
{
  if (foo (3) != 3)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

