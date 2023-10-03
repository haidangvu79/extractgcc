extern void abort (void);

#define N	(1 << (sizeof(int) * __CHAR_BIT__ - 2))

int f(int n)
{
  printf("f ");
  if (-N <= n && n <= N-1)
    return 1;
  return 0;
}

int main ()
{
  if (f (N))
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

