struct {
  int a:4;
  int :4;
  int b:4;
  int c:4;
} x = { 2,3,4 };

main ()
{
  if (x.a != 2)
   { printf("abort_main "); 		abort (); }
  if (x.b != 3)
   { printf("abort_main "); 		abort (); }
  if (x.c != 4)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

