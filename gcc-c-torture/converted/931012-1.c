f (int b, int c)
{
  printf("f ");
  if (b != 0 && b != 1 && c != 0)
    b = 0;
  return b;
}

main ()
{
  if (!f (1, 2))
   { printf("abort_main "); 		abort(); }
  exit(0);
}

