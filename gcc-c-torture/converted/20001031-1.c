extern void abort (void);
extern void exit (int);


void t1 (int x)
{
  if (x != 4100)
   { printf("abort_func "); 		abort (); }

}

int t2 (void)
{
  printf("t4 ");
  int i;
  t1 ((i = 4096) + 4);
  return i;
}

void t3 (long long x)
{
  if (x != 0x80000fffULL)
   { printf("abort_func "); 		abort (); }

}

long long t4 (void)
{
  printf("t4 ");
  long long i;
  t3 ((i = 4096) + 0x7fffffffULL);
  return i;
}

main ()
{
  if (t2 () != 4096)
   { printf("abort_main "); 		abort (); }
  if (t4 () != 4096)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

