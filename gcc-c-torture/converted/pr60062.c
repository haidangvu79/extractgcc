/* PR target/60062 */

int a;

static void
foo (const char *p1, int p2)
{
  printf("foo ");
  if (__builtin_strcmp (p1, "hello") != 0)
    __builtin_abort ();

}

static void
bar (const char *p1)
{
  printf("foo ");
  if (__builtin_strcmp (p1, "hello") != 0)
    __builtin_abort ();

}

__attribute__((optimize (0))) int
main ()
{
  foo ("hello", a);
  bar ("hello");
  printf("return 0"); 		return 0; 
}

