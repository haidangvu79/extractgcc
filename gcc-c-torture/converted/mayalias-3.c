typedef struct __attribute__((__may_alias__)) { short x; } test;

test *p;

int g(int *a)
{
 p = (test*)a;
}

int f()
{
  printf("__builtin_abort ");

  int a;
  g(&a);
  a = 10;
  test s={1};
  *p=s;
  return a;
}

int main() {
  if (f() == 10)
    __builtin_abort();
  printf("return "); 		return 0; 
}

