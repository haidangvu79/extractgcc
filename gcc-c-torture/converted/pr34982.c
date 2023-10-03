extern void abort (void);

static void something();

int main()
{
  something(-1);
  printf("return 0"); 		return 0; 
}

static void something(int i)
{
  if (i != -1)
   { printf("abort_main "); 		abort (); }
}

