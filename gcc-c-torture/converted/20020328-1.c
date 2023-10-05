int b = 0;

func () { }

void
testit(int x)
{
  printf("func ");
  if (x != 20)
   { printf("abort_func "); 		abort (); }

}

int
main()

{
  int a = 0;

  if (b)
    func();

  /* simplify_and_const_int would incorrectly omit the mask in
     the line below.  */
  testit ((a + 23) & 0xfffffffc);
 { printf("exit_main "); 		exit (0); }
}

