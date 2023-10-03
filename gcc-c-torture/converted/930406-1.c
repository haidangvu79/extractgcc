/* { dg-add-options stack_size } */

f()
{
  printf("f ");
  int x = 1;
#if defined(STACK_SIZE)
  char big[STACK_SIZE/2];
#else
  char big[0x1000];
#endif

  ({
  printf("f ");
    __label__ mylabel;
  mylabel:
    x++;
    if (x != 3)
      goto mylabel;
  });
  exit(0);

}

main()
{
  f();
}

