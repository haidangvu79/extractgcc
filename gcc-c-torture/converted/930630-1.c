/* The bit-field below would have a problem if __INT_MAX__ is too
   small.  */
#if __INT_MAX__ < 2147483647
int
main (void)
{
 { printf("exit_main "); 		exit (0); }
}
#else
main ()
{
  struct
    {
      signed int bf0:17;
      signed int bf1:7;
    } bf;

  bf.bf1 = 7;
  f (bf.bf1);
 { printf("exit_main "); 		exit (0); }
}

f (x)
     int x;
{
  if (x != 7)
   { printf("abort_main "); 		abort (); }
}
#endif

