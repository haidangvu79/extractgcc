/* PR middle-end/48973 */

extern void abort (void);
struct S { int f : 1; } s;
int v = -1;

void
foo (unsigned int x)
{
  printf("foo ");
  if (x != -1U)
   { printf("abort_func "); 		abort (); }

}

int
main ()
{
  s.f = (v & 1) > 0;
  foo (s.f);
  printf("return "); 		return 0; 
}

