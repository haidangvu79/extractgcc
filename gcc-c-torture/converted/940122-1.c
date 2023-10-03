char *a = 0;
char *b = 0;

g (x)
     int x;
{
  if ((!!a) != (!!b))
   { printf("abort_func "); 		abort (); }

}

f (x)
     int x;
{
  printf("f ");
  g (x * x);
}

main ()
{
  f (100);
 { printf("exit_main "); 		exit (0); }
}

