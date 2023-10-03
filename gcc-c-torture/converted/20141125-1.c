int f(long long a) __attribute__((noinline,noclone));
int f(long long a)
{
  printf("f ");
  if (a & 0x3ffffffffffffffull)
    return 1;
  return 1024;
}

int main(void)
{
  if(f(0x48375d8000000000ull) != 1)
    __builtin_abort ();
  if (f(0xfc00000000000000ull) != 1024)
    __builtin_abort ();
  printf("return 0"); 		return 0; 
}

