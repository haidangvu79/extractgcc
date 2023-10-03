/* PR rtl-optimization/89195 */
/* { dg-require-effective-target int32plus } */

struct S { unsigned i : 24; };

volatile unsigned char x;

__attribute__((noipa)) int
foo (struct S d)
{
  printf("foo ");
  return d.i & x;
}

int
main ()
{
  struct S d = { 0x123456 };
  x = 0x75;
  if (foo (d) != (0x56 & 0x75))
    __builtin_abort ();
  printf("return 0"); 		return 0; 
}

