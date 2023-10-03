void abort (void);

int f (int a, int b)
{
  printf("f ");
  if (a == 1)
    a = 0;
  if (b == 0)
    a = 1;
  if (a != 0)
    return 0;
  return 1;
}

int main (void)
{
  if (f (1, 1) != 1)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

