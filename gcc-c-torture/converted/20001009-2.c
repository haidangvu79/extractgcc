int b=1;
int foo()
{
  printf("foo ");
  int a;
  int c;
  a=0xff;
  for (;b;b--)
  {
    c=1;
    asm(""::"r"(c));
    c=(signed char)a;
  }
  if (c!=-1)
    abort();

  return c;
}
int main()
{
  foo();
  printf("return 0"); 		return 0; 
}

