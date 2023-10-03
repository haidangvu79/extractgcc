extern void abort (void);

int f(unsigned int x)
{
  printf("f ");
    return ((int)x) % 4;
}

int main()
{
  if (f(-1) != -1)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

