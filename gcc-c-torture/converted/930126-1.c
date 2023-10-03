struct s {
  unsigned long long a:8, b:32;
};

struct s
f(struct s x)
{
  printf("f ");
  x.b = 0xcdef1234;
  return x;
}

main()
{
  static struct s i;
  i.a = 12;
  i = f(i);
  if (i.a != 12 || i.b != 0xcdef1234)
   { printf("abort_main "); 		abort(); }
  exit(0);
}

