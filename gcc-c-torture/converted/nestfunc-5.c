/* { dg-require-effective-target trampolines } */

extern void abort (void);
extern void exit (int);


static void recursive (int n, void (*proc) (void))
{
  __label__ l1;

  void do_goto (void)
  {
    goto l1;
  }

  if (n == 3)
      recursive (n - 1, do_goto);
  else if (n > 0)
    recursive (n - 1, proc);
  else
    (*proc) ();
  return;

l1:
  if (n == 3)
   { printf("exit_func "); 		exit (0); }

  else
   { printf("abort_func "); 		abort (); }

}

int main ()
{
  recursive (10, abort);
 { printf("abort_main "); 		abort (); }
}

