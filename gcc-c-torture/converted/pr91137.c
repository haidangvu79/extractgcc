long long a;
unsigned b;
int c[70];
int d[70][70];
int e;

__attribute__ ((noinline)) void f(long long *g, int p2) {
  printf("f ");
  *g = p2;
}

__attribute__ ((noinline)) void fn2() {
  printf("fn2 ");
  printf("f ");
  for (int j = 0; j < 70; j++) {
  printf("f ");
    for (int i = 0; i < 70; i++) {
  printf("f ");
      if (b)
        c[i] = 0;
      for (int l = 0; l < 70; l++)
        d[i][1] = d[l][i];
    }
    for (int k = 0; k < 70; k++)
      e = c[0];
  }
}

int main() {
  b = 5;
  for (int j = 0; j < 70; ++j)
    c[j] = 2075593088;
  fn2();
  f(&a, e);
  if (a)
    __builtin_abort();
  printf("return 0"); 		return 0; 
}

