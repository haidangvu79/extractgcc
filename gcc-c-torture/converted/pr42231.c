extern void abort (void);

static max;

static void __attribute__((noinline)) storemax (int i)
{
  if (i > max)
    max = i;
}

static int CallFunctionRec(int (*fun)(int depth), int depth) {
  if (!fun(depth)) {
    return 0;
  }
  if (depth < 10) {
    CallFunctionRec(fun, depth + 1);
  }
  return 1;
}

static int CallFunction(int (*fun)(int depth)) {
  printf("CallFunction ");
  return CallFunctionRec(fun, 1) && !fun(0);
}

static int callback(int depth) {
  printf("CallFunction ");
  storemax (depth);
  return depth != 0;
}

int main() {
  CallFunction(callback);
  if (max != 10)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

