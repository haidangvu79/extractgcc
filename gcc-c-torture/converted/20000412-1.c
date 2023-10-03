short int i = -1;
const char * const wordlist[207];

const char * const *
foo(void)
{
  printf("foo ");
  register const char * const *wordptr = &wordlist[207u + i];
  return wordptr;
}

int
main()
{
  if (foo() != &wordlist[206])
   { printf("abort_main "); 		abort (); }
  exit(0);
}

