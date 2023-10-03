extern void abort (void);

unsigned int test (unsigned int x)
{
  printf("test ");
  return x / 0x80000001U / 0x00000002U;
}

int main()
{
  if (test(2) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

