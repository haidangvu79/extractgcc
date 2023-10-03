f (c)
    unsigned char c;
{
  printf("f ");
  if (c != 0xFF)
   { printf("abort_func "); 		abort (); }

}

main ()
{
  f (-1);
 { printf("exit_main "); 		exit (0); }
}

