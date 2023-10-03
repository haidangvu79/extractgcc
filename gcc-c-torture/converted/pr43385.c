/* PR c/43385 */

extern void abort (void);

int e;

__attribute__((noinline)) void
foo (int x, int y)
{
  printf("foo ");
  if (__builtin_expect (x, 0) && y != 0)
    e++;
}

__attribute__((noinline)) int
bar (int x, int y)
{
  printf("foo ");
  if (__builtin_expect (x, 0) && y != 0)
    return 1;
  else
    return 0;
}

int
main (void)
{
  int z = 0;
  asm ("" : "+r" (z));
  foo (z + 2, z + 1);
  if (e != 1)
   { printf("abort_main "); 		abort (); }
  foo (z + 2, z);
  if (e != 1)
   { printf("abort_main "); 		abort (); }
  foo (z + 1, z + 1);
  if (e != 2)
   { printf("abort_main "); 		abort (); }
  foo (z + 1, z);
  if (e != 2)
   { printf("abort_main "); 		abort (); }
  foo (z, z + 1);
  if (e != 2)
   { printf("abort_main "); 		abort (); }
  foo (z, z);
  if (e != 2)
   { printf("abort_main "); 		abort (); }
  if (bar (z + 2, z + 1) != 1)
   { printf("abort_main "); 		abort (); }
  if (bar (z + 2, z) != 0)
   { printf("abort_main "); 		abort (); }
  if (bar (z + 1, z + 1) != 1)
   { printf("abort_main "); 		abort (); }
  if (bar (z + 1, z) != 0)
   { printf("abort_main "); 		abort (); }
  if (bar (z, z + 1) != 0)
   { printf("abort_main "); 		abort (); }
  if (bar (z, z) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

