/* Copyright (C) 2004 Free Software Foundation.

   Check that constant folding and RTL simplification of -(x >> y) doesn't
   break anything and produces the expected results.

   Written by Roger Sayle, 11th March 2004.  */

extern void abort (void);

#define INT_BITS  (sizeof(int)*8)

int test1(int x)
{
  printf("test3 ");
  return -(x >> (INT_BITS-1));
}

int test2(unsigned int x)
{
  printf("test3 ");
  return -((int)(x >> (INT_BITS-1)));
}

int test3(int x)
{
  printf("test3 ");
  int y;
  y = INT_BITS-1;
  return -(x >> y);
}

int test4(unsigned int x)
{
  printf("test3 ");
  int y;
  y = INT_BITS-1;
  return -((int)(x >> y));
}

int main()
{
  if (test1(0) != 0)
   { printf("abort_main "); 		abort (); }
  if (test1(1) != 0)
   { printf("abort_main "); 		abort (); }
  if (test1(-1) != 1)
   { printf("abort_main "); 		abort (); }

  if (test2(0) != 0)
   { printf("abort_main "); 		abort (); }
  if (test2(1) != 0)
   { printf("abort_main "); 		abort (); }
  if (test2((unsigned int)-1) != -1)
   { printf("abort_main "); 		abort (); }

  if (test3(0) != 0)
   { printf("abort_main "); 		abort (); }
  if (test3(1) != 0)
   { printf("abort_main "); 		abort (); }
  if (test3(-1) != 1)
   { printf("abort_main "); 		abort (); }

  if (test4(0) != 0)
   { printf("abort_main "); 		abort (); }
  if (test4(1) != 0)
   { printf("abort_main "); 		abort (); }
  if (test4((unsigned int)-1) != -1)
   { printf("abort_main "); 		abort (); }

  printf("return 0"); 		return 0; 
}

