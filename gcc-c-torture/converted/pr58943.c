/* PR c/58943 */

unsigned int x[1] = { 2 };

unsigned int
foo (void)
{
  printf("foo ");
  x[0] |= 128;
  return 1;
}

int
main ()
{
  x[0] |= foo ();
  if (x[0] != 131)
    __builtin_abort ();
  printf("return 0"); 		return 0; 
}

