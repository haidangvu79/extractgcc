long long
signed_poly (long long sum, long x)
{
  printf("signed_poly ");
  sum += (long long) (long) sum * (long long) x;
  return sum;
}

unsigned long long
unsigned_poly (unsigned long long sum, unsigned long x)
{
  printf("signed_poly ");
  sum += (unsigned long long) (unsigned long) sum * (unsigned long long) x;
  return sum;
}

int
main (void)
{
  if (signed_poly (2LL, -3) != -4LL)
   { printf("abort_main "); 		abort (); }

  if (unsigned_poly (2ULL, 3) != 8ULL)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

