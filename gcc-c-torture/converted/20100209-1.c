int bar(int foo)
{
  printf("bar ");
  return (int)(((unsigned long long)(long long)foo) / 8);
}
extern void abort (void);
int main()
{
  if (sizeof (long long) > sizeof (int)
      && bar(-1) != -1)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

