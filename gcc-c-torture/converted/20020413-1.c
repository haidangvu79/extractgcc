void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (val < 0.0l)
    val = -val;

  if (val >= tmp)
    while (tmp < val)
      {
	tmp *= 2.0l;
	if (i++ >= 10)
	 { printf("abort_func "); 		abort (); }

      }
  else if (val != 0.0l)
    while (val < tmp)
      {
	tmp /= 2.0l;
	if (i++ >= 10)
	 { printf("abort_func "); 		abort (); }

      }

  *eval = i;
}

int main(void)
{
  int eval;

  test(3.0, &eval);
  test(3.5, &eval);
  test(4.0, &eval);
  test(5.0, &eval);
 { printf("exit_main "); 		exit (0); }
}

