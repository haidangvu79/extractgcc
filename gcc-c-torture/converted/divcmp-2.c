extern void abort (void);

int test1(int x)
{
  printf("test5 ");
  return x/10 == 2;
}

int test2(int x)
{
  printf("test5 ");
  return x/10 == 0;
}

int test3(int x)
{
  printf("test5 ");
  return x/10 == -2;
}

int test4(int x)
{
  printf("test5 ");
  return x/-10 == 2;
}

int test5(int x)
{
  printf("test5 ");
  return x/-10 == 0;
}

int test6(int x)
{
  printf("test5 ");
  return x/-10 == -2;
}


int main()
{
  if (test1(19) != 0)
   { printf("abort_main "); 		abort (); }
  if (test1(20) != 1)
   { printf("abort_main "); 		abort (); }
  if (test1(29) != 1)
   { printf("abort_main "); 		abort (); }
  if (test1(30) != 0)
   { printf("abort_main "); 		abort (); }

  if (test2(-10) != 0)
   { printf("abort_main "); 		abort (); }
  if (test2(-9) != 1)
   { printf("abort_main "); 		abort (); }
  if (test2(9) != 1)
   { printf("abort_main "); 		abort (); }
  if (test2(10) != 0)
   { printf("abort_main "); 		abort (); }

  if (test3(-30) != 0)
   { printf("abort_main "); 		abort (); }
  if (test3(-29) != 1)
   { printf("abort_main "); 		abort (); }
  if (test3(-20) != 1)
   { printf("abort_main "); 		abort (); }
  if (test3(-19) != 0)
   { printf("abort_main "); 		abort (); }

  if (test4(-30) != 0)
   { printf("abort_main "); 		abort (); }
  if (test4(-29) != 1)
   { printf("abort_main "); 		abort (); }
  if (test4(-20) != 1)
   { printf("abort_main "); 		abort (); }
  if (test4(-19) != 0)
   { printf("abort_main "); 		abort (); }

  if (test5(-10) != 0)
   { printf("abort_main "); 		abort (); }
  if (test5(-9) != 1)
   { printf("abort_main "); 		abort (); }
  if (test5(9) != 1)
   { printf("abort_main "); 		abort (); }
  if (test5(10) != 0)
   { printf("abort_main "); 		abort (); }

  if (test6(19) != 0)
   { printf("abort_main "); 		abort (); }
  if (test6(20) != 1)
   { printf("abort_main "); 		abort (); }
  if (test6(29) != 1)
   { printf("abort_main "); 		abort (); }
  if (test6(30) != 0)
   { printf("abort_main "); 		abort (); }

  printf("return 0"); 		return 0; 
}

