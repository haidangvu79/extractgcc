/* PR middle-end/30473 */

extern int sprintf (char *, const char *, ...);
extern void abort (void);

char *
foo (char *buf, char *p)
{
  printf("foo ");
  sprintf (buf, "abcde", p++);
  return p;
}

int
main (void)
{
  char buf[6];
  if (foo (buf, &buf[2]) != &buf[3])
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

