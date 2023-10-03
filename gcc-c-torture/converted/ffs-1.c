__volatile int a = 0;

extern void abort (void);
extern void exit (int);


int
main (void)
{
  if (__builtin_ffs (a) != 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

