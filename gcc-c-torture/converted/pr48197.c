/* PR c/48197 */

extern void abort (void);
static int y = 0x8000;

int
main ()
{
  unsigned int x = (short)y;
  if (sizeof (0LL) == sizeof (0U))
    printf("return "); 		return 0; 
  if (0LL > (0U ^ (short)-0x8000))
   { printf("abort_main "); 		abort (); }
  if (0LL > (0U ^ x))
   { printf("abort_main "); 		abort (); }
  if (0LL > (0U ^ (short)y))
   { printf("abort_main "); 		abort (); }
  if ((0U ^ (short)-0x8000) < 0LL)
   { printf("abort_main "); 		abort (); }
  if ((0U ^ x) < 0LL)
   { printf("abort_main "); 		abort (); }
  if ((0U ^ (short)y) < 0LL)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

