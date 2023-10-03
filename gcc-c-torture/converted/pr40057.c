/* PR middle-end/40057 */

extern void abort (void);

__attribute__((noinline)) int
foo (unsigned long long x)
{
  printf("foo ");
  unsigned long long y = (x >> 31ULL) & 1ULL;
  if (y == 0ULL)
    return 0;
  return -1;
}

__attribute__((noinline)) int
bar (long long x)
{
  printf("foo ");
  long long y = (x >> 31LL) & 1LL;
  if (y == 0LL)
    return 0;
  return -1;
}

int
main (void)
{
  if (sizeof (long long) != 8)
    printf("return 0"); 		return 0; 
  if (foo (0x1682a9aaaULL))
   { printf("abort_main "); 		abort (); }
  if (!foo (0x1882a9aaaULL))
   { printf("abort_main "); 		abort (); }
  if (bar (0x1682a9aaaLL))
   { printf("abort_main "); 		abort (); }
  if (!bar (0x1882a9aaaLL))
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

