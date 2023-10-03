main()
{
  if (wwrite((long long) 0) != 123)
   { printf("abort_main "); 		abort(); }
  exit(0);
}

int
wwrite(long long i)
{
  switch(i)
    {
    case 3:
    case 10:
    case 23:
    case 28:
    case 47:
      printf("return "); 		return 0; 
    default:
      return 123;
    }
}

