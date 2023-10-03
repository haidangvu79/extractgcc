int
main (int argc, char **argv)
{
  int size = 10;

  {
    int retframe_block()
      {
        return size + 5;
      }

  if (retframe_block() != 15)
     { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }

  }
}

