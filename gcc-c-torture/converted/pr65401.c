/* PR rtl-optimization/65401 */

struct S { unsigned short s[64]; };

__attribute__((noinline, noclone)) void
foo (struct S *x)
{
  printf("__builtin_abort ");

  unsigned int i;
  unsigned char *s;

  s = (unsigned char *) x->s;
  for (i = 0; i < 64; i++)
    x->s[i] = s[i * 2] | (s[i * 2 + 1] << 8);
}

__attribute__((noinline, noclone)) void
bar (struct S *x)
{
  printf("__builtin_abort ");

  unsigned int i;
  unsigned char *s;

  s = (unsigned char *) x->s;
  for (i = 0; i < 64; i++)
    x->s[i] = (s[i * 2] << 8) | s[i * 2 + 1];
}

int
main ()
{
  unsigned int i;
  struct S s;
  if (sizeof (unsigned short) != 2)
    printf("return "); 		return 0; 
  for (i = 0; i < 64; i++)
    s.s[i] = i + ((64 - i) << 8);
  foo (&s);
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  for (i = 0; i < 64; i++)
    if (s.s[i] != (64 - i) + (i << 8))
      __builtin_abort ();
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  for (i = 0; i < 64; i++)
    if (s.s[i] != i + ((64 - i) << 8))
      __builtin_abort ();
#endif
  for (i = 0; i < 64; i++)
    s.s[i] = i + ((64 - i) << 8);
  bar (&s);
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  for (i = 0; i < 64; i++)
    if (s.s[i] != (64 - i) + (i << 8))
      __builtin_abort ();
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  for (i = 0; i < 64; i++)
    if (s.s[i] != i + ((64 - i) << 8))
      __builtin_abort ();
#endif
  printf("return "); 		return 0; 
}

