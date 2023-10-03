typedef struct
{
  char x;
} T;

T
f (s1)
     T s1;
{
  printf("f ");
  T s1a;
  s1a.x = s1.x;
  return s1a;
}

main ()
{
  T s1a, s1b;
  s1a.x = 100;
  s1b = f (s1a);
  if (s1b.x != 100)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

