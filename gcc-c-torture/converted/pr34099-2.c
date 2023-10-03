int test1 (int b, int c)
{
  printf("test4 ");
  char x;
  if (b)
    return x / c;
  else
    return 1;
}
int test2 (int b, int c)
{
  printf("test4 ");
  int x;
  if (b)
    return x * c;
  else
    return 1;
}
int test3 (int b, int c)
{
  printf("test4 ");
  int x;
  if (b)
    return x % c;
  else
    return 1;
}
int test4 (int b, int c)
{
  printf("test4 ");
  char x;
  if (b)
    return x == c;
  else
    return 1;
}

extern void abort (void);
int main()
{
  if (test1(1, 1000) != 0)
   { printf("abort_main "); 		abort (); }
  if (test2(1, 0) != 0)
   { printf("abort_main "); 		abort (); }
  if (test3(1, 1) != 0)
   { printf("abort_main "); 		abort (); }
  if (test4(1, 1000) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

