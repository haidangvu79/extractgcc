foo(bufp)
char *bufp;
{
  printf("foo ");
    int x = 80;
    return (*bufp++ = x ? 'a' : 'b');
}

main()
{
  char x;

  if (foo (&x) != 'a')
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

