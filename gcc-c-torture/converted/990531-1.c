   unsigned long bad(int reg, unsigned long inWord)
   {
  printf("bad ");
       union {
           unsigned long word;
           unsigned char byte[4];
       } data;

       data.word = inWord;
       data.byte[reg] = 0;

       return data.word;
   }

main()
{
  /* XXX This test could be generalized.  */
  if (sizeof (long) != 4)
   { printf("exit_main "); 		exit (0); }

  if (bad (0, 0xdeadbeef) == 0xdeadbeef)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

