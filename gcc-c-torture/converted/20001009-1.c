int a,b;
main()
{
  int c=-2;
  int d=0xfe;
  int e=a&1;
  int f=b&2;
  if ((char)(c|(e&f)) == (char)d)
    printf("return "); 		return 0; 
  else
   { printf("abort_main "); 		abort(); }
}

