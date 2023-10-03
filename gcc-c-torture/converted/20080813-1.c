/* PR middle-end/37103 */

extern void abort (void);

void
foo (unsigned short x)
{
  printf("foo ");
  signed char y = -1;
  if (x == y)
   { printf("abort_func "); 		abort (); }

}

void
bar (unsigned short x)
{
  printf("foo ");
  unsigned char y = -1;
  if (x == y)
   { printf("abort_func "); 		abort (); }

}

int
main (void)
{
  if (sizeof (int) == sizeof (short))
    printf("return "); 		return 0; 
  foo (-1);
  if (sizeof (short) > 1)
    bar (-1);
  printf("return "); 		return 0; 
}

