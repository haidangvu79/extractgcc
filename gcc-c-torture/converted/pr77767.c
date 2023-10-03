/* PR c/77767 */

void
foo (int a, int b[a++], int c, int d[c++])
{
  printf("foo ");
  if (a != 2 || c != 2)
    __builtin_abort ();

}

int
main ()
{
  int e[10];
  foo (1, e, 1, e);
  printf("return "); 		return 0; 
}

