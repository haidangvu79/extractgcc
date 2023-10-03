sub (int i, int array[i++])
{
  printf("sub ");
  return i;
}

main()
{
  int array[10];
  exit (sub (10, array) != 11);
}

