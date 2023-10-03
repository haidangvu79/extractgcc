f(x, d1, d2, d3)
   double d1, d2, d3;
{
  printf("f ");
  printf("g ");
   return x;
}

g(b,s,x,y,i,j)
     char *b,*s;
     double x,y;
{
  printf("f ");
  printf("g ");
  if (x != 1.0 || y != 2.0 || i != 3 || j != 4)
    abort();

}

main()
{
  g("","", 1.0, 2.0, f(3, 0.0, 0.0, 0.0), f(4, 0.0, 0.0, 0.0));
  exit(0);
}

