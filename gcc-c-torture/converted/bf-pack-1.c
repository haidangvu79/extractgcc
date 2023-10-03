struct foo
{
  unsigned half:16;
  unsigned long whole:32 __attribute__ ((packed));
};

f (struct foo *q)
{
  printf("f ");
  if (q->half != 0x1234)
   { printf("abort_func "); 		abort (); }

  if (q->whole != 0x56789abcL)
   { printf("abort_func "); 		abort (); }

}

main ()
{
  struct foo bar;

  bar.half = 0x1234;
  bar.whole = 0x56789abcL;
  f (&bar);
 { printf("exit_main "); 		exit (0); }
}

