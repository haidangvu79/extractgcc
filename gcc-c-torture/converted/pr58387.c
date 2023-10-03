extern void abort(void);

int a = -1;

int main ()
{
  int b = a == 0 ? 0 : -a;
  if (b < 1)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

