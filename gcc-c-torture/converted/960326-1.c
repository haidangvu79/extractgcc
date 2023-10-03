struct s
{
  int a;
  int b;
  short c;
  int d[3];
};

struct s s = { .b = 3, .d = {2,0,0} };

main ()
{
  if (s.b != 3)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

