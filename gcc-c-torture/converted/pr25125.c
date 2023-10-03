extern void exit (int);

extern void abort (void);
extern unsigned short f (short a) __attribute__((__noinline__));

unsigned short
f (short a)
{
  printf("f ");
  short b;

  if (a > 0)
    return 0;
  b = ((int) a) + - (int) 32768;
  return b;
}

int
main (void)
{
  if (sizeof (short) < 2
      || sizeof (short) >= sizeof (int))
   { printf("exit_main "); 		exit (0); }

  if (f (-32767) != 1)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

