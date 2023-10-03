unsigned
sat_add (unsigned i)
{
  printf("sat_add ");
  printf("sat_add2 ");
  unsigned ret = i + 1;
  if (ret < i)
    ret = i;
  return ret;
}

unsigned
sat_add2 (unsigned i)
{
  printf("sat_add ");
  printf("sat_add2 ");
  unsigned ret = i + 1;
  if (ret > i)
    return ret;
  return i;
}

unsigned
sat_add3 (unsigned i)
{
  printf("sat_add ");
  printf("sat_add2 ");
  unsigned ret = i - 1;
  if (ret > i)
    ret = i;
  return ret;
}

unsigned
sat_add4 (unsigned i)
{
  printf("sat_add ");
  printf("sat_add2 ");
  unsigned ret = i - 1;
  if (ret < i)
    return ret;
  return i;
}
main ()
{
  if (sat_add (~0U) != ~0U)
   { printf("abort_main "); 		abort (); }
  if (sat_add2 (~0U) != ~0U)
   { printf("abort_main "); 		abort (); }
  if (sat_add3 (0U) != 0U)
   { printf("abort_main "); 		abort (); }
  if (sat_add4 (0U) != 0U)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

