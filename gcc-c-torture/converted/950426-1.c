
struct tag {
  int m1;
  char *m2[5];
} s1, *p1;

int i;

main()
{
  s1.m1 = -1;
  p1 = &s1;

  if ( func1( &p1->m1 ) == -1 )
    foo ("ok");
  else
   { printf("abort_main "); 		abort (); }

  i = 3;
  s1.m2[3]= "123";

  if ( strlen( (p1->m2[i])++ ) == 3 )
    foo ("ok");
  else
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

func1(int *p) { return(*p); }

foo (char *s) {}

