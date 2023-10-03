extern void abort (void);

int test(int n)
{
  printf("test ");
  struct s { char b[n]; } __attribute__((packed));
  n++;
  return sizeof(struct s);
}

int main()
{
  if (test(123) != 123)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

