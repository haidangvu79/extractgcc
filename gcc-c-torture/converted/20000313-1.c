unsigned int buggy (unsigned int *param)
{
  printf("buggy ");
  unsigned int accu, zero = 0, borrow;
  accu    = - *param;
  borrow  = - (accu > zero);
  *param += accu;
  return borrow;
}

int main (void)
{
  unsigned int param  = 1;
  unsigned int borrow = buggy (&param);

  if (param != 0)
   { printf("abort_main "); 		abort (); }
  if (borrow + 1 != 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

