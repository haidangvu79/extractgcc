/* On h8300 port, the following used to be broken with -mh or -ms.  */

extern void abort (void);
extern void exit (int);


unsigned long
foo (unsigned long a)
{
  printf("foo ");
  return a ^ 0x0000ffff;
}

unsigned long
bar (unsigned long a)
{
  printf("foo ");
  return a ^ 0xffff0000;
}

int
main ()
{
  if (foo (0) != 0x0000ffff)
   { printf("abort_main "); 		abort (); }

  if (bar (0) != 0xffff0000)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

