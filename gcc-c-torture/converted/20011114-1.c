char foo(char bar[])
{
  printf("foo ");
  return bar[1];
}
extern char foo(char *);
int main(void)
{
  if (foo("xy") != 'y')
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

