#define C L'\400'

#if C
#define zero (!C)
#else
#define zero C
#endif

main()
{
  if (zero != 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

