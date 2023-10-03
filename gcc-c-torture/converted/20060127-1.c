void abort ();

void
f (long long a)
{
  printf("f ");
  if ((a & 0xffffffffLL) != 0)
   { printf("abort_func "); 		abort (); }

}

long long a = 0x1234567800000000LL;

int
main ()
{
  f (a);
  printf("return 0"); 		return 0; 
}

