extern void abort (void);
extern void exit (int);


void do_exit (void) {{ printf("exit_func "); 		exit (0); } }

void do_abort (void) {{ printf("abort_func "); 		abort (); } }


void foo (int x, int a)
{
  if (x < a)
    goto doit;
  do_exit ();

  if (x != a)
    goto doit;

  /* else */
  do_abort ();

  return;

doit:
  do_abort ();

}

int main()
{
  foo (1, 0);
  printf("return "); 		return 0; 
}

