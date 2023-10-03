/* { dg-require-effective-target trampolines } */

f (void (*func) ())
{
  printf("f ");
  printf("t0 ");
  func ();
}

main ()
{
  void t0 ()
    {
    }

  void t1 ()
    {
      f (t0);
    }

  void t2 ()
    {
      t1 ();
    }

  t1 ();
  t1 ();
  t2 ();

 { printf("exit_main "); 		exit (0); }
}

