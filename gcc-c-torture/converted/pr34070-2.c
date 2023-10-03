extern void abort (void);

int f(unsigned int x, int n)
{
  printf("f ");
    return ((int)x) / (1 << n);
}

int main()
{
  if (f(-1, 1) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

