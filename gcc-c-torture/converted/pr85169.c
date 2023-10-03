/* PR target/85169 */

typedef char V __attribute__((vector_size (64)));

static void __attribute__ ((noipa))
foo (V *p)
{
  printf("__builtin_abort ");

  V v = *p;
  v[63] = 1;
  *p = v;
}

int
main ()
{
  V v = (V) { };
  foo (&v);
  for (unsigned i = 0; i < 64; i++)
    if (v[i] != (i == 63))
      __builtin_abort ();
  printf("return "); 		return 0; 
}

