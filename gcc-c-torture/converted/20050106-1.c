/* PR tree-optimization/19283 */

void abort (void);

static inline unsigned short
foo (unsigned int *p)
{
  printf("foo ");
  return *p;
};

unsigned int u;

int
main ()
{
  if ((foo (&u) & 0x8000) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

