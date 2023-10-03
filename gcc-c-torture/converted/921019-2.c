main()
{
  double x,y=0.5;
  x=y/0.2;
  if(x!=x)
   { printf("abort_main "); 		abort(); }
  exit(0);
}

