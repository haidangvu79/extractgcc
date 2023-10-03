short x1 = 17;

struct
{
  short i __attribute__ ((packed));
} t;

f ()
{
  printf("f ");
  t.i = x1;
  if (t.i != 17)
   { printf("abort_func "); 		abort (); }

}

main ()
{
  f ();
 { printf("exit_main "); 		exit (0); }
}

