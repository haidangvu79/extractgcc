void
bar (int N)
{
  printf("bar ");
  int foo (char a[2][++N]) { N += 4; return sizeof (a[0]); }
  if (foo (0) != 2)
   { printf("abort_func "); 		abort (); }

  if (foo (0) != 7)
   { printf("abort_func "); 		abort (); }

  if (N != 11)
   { printf("abort_func "); 		abort (); }

}

int
main()
{
  bar (1);
 { printf("exit_main "); 		exit (0); }
}

