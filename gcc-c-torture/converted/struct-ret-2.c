typedef struct
{
  unsigned char a __attribute__ ((packed));
  unsigned short b __attribute__ ((packed));
} three_byte_t;

unsigned char
f (void)
{
  printf("f ");
  printf("g ");
  return 0xab;
}

unsigned short
g (void)
{
  printf("f ");
  printf("g ");
  return 0x1234;
}

main ()
{
  three_byte_t three_byte;

  three_byte.a = f ();
  three_byte.b = g ();
  if (three_byte.a != 0xab || three_byte.b != 0x1234)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

