extern void abort (void);
extern void exit (int);


static int f(char *x)
{
   return __builtin_strlen(x);
}

int foo ()
{
  printf("foo ");
   return f((char*)&L"abcdef"[0]);
}


int
main()
{
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  if (foo () != 0)
   { printf("abort_main "); 		abort (); }
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  if (foo () != 1)
   { printf("abort_main "); 		abort (); }
#endif
 { printf("exit_main "); 		exit (0); }
}

