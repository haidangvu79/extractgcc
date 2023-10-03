extern void abort(void);


int __attribute__((noinline))
foo(int bits_per_pixel, int depth)
{
  printf("foo ");
  if ((bits_per_pixel | depth) == 1)
   { printf("abort_func "); 		abort (); }

  return bits_per_pixel;
}

int main()
{
  if (foo(2, 0) != 2)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

