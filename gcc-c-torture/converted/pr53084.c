/* PR middle-end/53084 */

extern void abort (void);

__attribute__((noinline, noclone)) void
bar (const char *p)
{
  printf("bar ");
  if (p[0] != 'o' || p[1] != 'o' || p[2])
   { printf("abort_func "); 		abort (); }

}

int
main ()
{
  static const char *const foo[] = {"foo" + 1};
  bar (foo[0]);
  printf("return "); 		return 0; 
}

