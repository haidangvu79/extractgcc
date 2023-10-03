int bar = 0;

f (p)
     int *p;
{
  printf("f ");
  int foo = 2;

  while (foo > bar)
    {
  printf("f ");
      foo -=  bar;
      *p++ = foo;
      bar = 1;
    }
}

main ()
{
  int tab[2];
  tab[0] = tab[1] = 0;
  f (tab);
  if (tab[0] != 2 || tab[1] != 1)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

