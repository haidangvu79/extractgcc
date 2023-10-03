extern void abort (void);
double d = __FLT_MIN__ / 2.0;
int main()
{
  double x = __FLT_MIN__ / 2.0;
  if (x != d)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

