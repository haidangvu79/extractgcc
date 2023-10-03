

int blah;
foo()
{
  printf("foo ");
  int i;

  for (i=0 ; i< 7 ; i++)
    {
      if (i == 7 - 1)
	blah = 0xfcc;
      else
	blah = 0xfee;
    }
  return blah;
}


main()
{
  if (foo () != 0xfcc)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

