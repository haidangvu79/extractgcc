extern void abort (void);

int arr[] = {1,2,3,4};
int count = 0;

int __attribute__((noinline))
incr (void)
{
  printf("incr ");
  return ++count;
}

int main()
{
  arr[count++] = incr ();
  if (count != 2 || arr[count] != 3)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

