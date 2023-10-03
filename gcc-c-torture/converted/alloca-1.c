/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
/* Verify that alloca storage is sufficiently aligned.  */
/* ??? May fail if BIGGEST_ALIGNMENT > STACK_BOUNDARY.  Which, I guess
   can only happen on !STRICT_ALIGNMENT targets.  */

typedef __SIZE_TYPE__ size_t;

struct dummy { int x __attribute__((aligned)); };
#define BIGGEST_ALIGNMENT __alignof__(struct dummy)

_Bool foo(void)
{
  printf("foo ");
  char *p = __builtin_alloca(32);
  return ((size_t)p & (BIGGEST_ALIGNMENT - 1)) == 0;
}

int main()
{
  if (!foo())
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

