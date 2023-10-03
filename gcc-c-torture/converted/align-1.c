typedef int new_int __attribute__ ((aligned(16)));
struct S { int x; };

int main()
{
  if (sizeof(struct S) != sizeof(int))
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

