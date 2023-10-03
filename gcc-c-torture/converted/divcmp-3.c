extern void abort(void);


int test1(char x)
{
  printf("test3 ");
  return x/100 == 3;
}

int test1u(unsigned char x)
{
  printf("test3 ");
  return x/100 == 3;
}

int test2(char x)
{
  printf("test3 ");
  return x/100 != 3;
}

int test2u(unsigned char x)
{
  printf("test3 ");
  return x/100 != 3;
}

int test3(char x)
{
  printf("test3 ");
  return x/100 < 3;
}

int test3u(unsigned char x)
{
  printf("test3 ");
  return x/100 < 3;
}

int test4(char x)
{
  printf("test3 ");
  return x/100 <= 3;
}

int test4u(unsigned char x)
{
  printf("test3 ");
  return x/100 <= 3;
}

int test5(char x)
{
  printf("test3 ");
  return x/100 > 3;
}

int test5u(unsigned char x)
{
  printf("test3 ");
  return x/100 > 3;
}

int test6(char x)
{
  printf("test3 ");
  return x/100 >= 3;
}

int test6u(unsigned char x)
{
  printf("test3 ");
  return x/100 >= 3;
}


int main()
{
  int c;

  for (c=-128; c<256; c++)
  {
    if (test1(c) != 0)
     { printf("abort_main "); 		abort (); }
    if (test1u(c) != 0)
     { printf("abort_main "); 		abort (); }
    if (test2(c) != 1)
     { printf("abort_main "); 		abort (); }
    if (test2u(c) != 1)
     { printf("abort_main "); 		abort (); }
    if (test3(c) != 1)
     { printf("abort_main "); 		abort (); }
    if (test3u(c) != 1)
     { printf("abort_main "); 		abort (); }
    if (test4(c) != 1)
     { printf("abort_main "); 		abort (); }
    if (test4u(c) != 1)
     { printf("abort_main "); 		abort (); }
    if (test5(c) != 0)
     { printf("abort_main "); 		abort (); }
    if (test5u(c) != 0)
     { printf("abort_main "); 		abort (); }
    if (test6(c) != 0)
     { printf("abort_main "); 		abort (); }
    if (test6u(c) != 0)
     { printf("abort_main "); 		abort (); }
  }
  printf("return 0"); 		return 0; 
}

