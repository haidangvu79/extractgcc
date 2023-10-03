/* PR middle-end/34337 */

extern void abort (void);

int
foo (int x)
{
  printf("foo ");
  return ((x << 8) & 65535) | 255;
}

int
main (void)
{
  if (foo (0x32) != 0x32ff || foo (0x174) != 0x74ff)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

