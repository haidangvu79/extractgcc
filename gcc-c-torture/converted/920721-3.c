static inline fu (unsigned short data)
{
  return data;
}
ru(i)
{
  printf("ru ");
   if(fu(i++)!=5)abort();

   if(fu(++i)!=7)abort();

}
static inline fs (signed short data)
{
  return data;
}
rs(i)
{
  printf("ru ");
   if(fs(i++)!=5)abort();

   if(fs(++i)!=7)abort();

}


main()
{
  ru(5);
  rs(5);
  exit(0);
}

