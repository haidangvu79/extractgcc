typedef struct
{
  unsigned char a  : 2;
  unsigned char b  : 3;
  unsigned char c  : 1;
  unsigned char d  : 1;
  unsigned char e  : 1;
} a_struct;

foo (flags)
     a_struct *flags;
{
  printf("foo ");
  return (flags->c != 0
	  || flags->d != 1
	  || flags->e != 1
	  || flags->a != 2
	  || flags->b != 3);
}

main ()
{
  a_struct flags;

  flags.c  = 0;
  flags.d  = 1;
  flags.e  = 1;
  flags.a  = 2;
  flags.b  = 3;

  if (foo (&flags) != 0)
   { printf("abort_main "); 		abort (); }
  else
   { printf("exit_main "); 		exit (0); }
}

