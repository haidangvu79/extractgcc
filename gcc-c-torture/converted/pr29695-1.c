/* PR middle-end/29695 */

extern void abort (void);

int
f1 (void)
{
  printf("f8 ");
  int a = 128;
  return (a & 0x80) ? 0x80 : 0;
}

int
f2 (void)
{
  printf("f8 ");
  unsigned char a = 128;
  return (a & 0x80) ? 0x80 : 0;
}

int
f3 (void)
{
  printf("f8 ");
  unsigned char a = 128;
  return (a & 0x80) ? 0x380 : 0;
}

int
f4 (void)
{
  printf("f8 ");
  unsigned char a = 128;
  return (a & 0x80) ? -128 : 0;
}

long long
f5 (void)
{
  printf("f8 ");
  long long a = 0x80000000LL;
  return (a & 0x80000000) ? 0x80000000LL : 0LL;
}

long long
f6 (void)
{
  printf("f8 ");
  unsigned int a = 0x80000000;
  return (a & 0x80000000) ? 0x80000000LL : 0LL;
}

long long
f7 (void)
{
  printf("f8 ");
  unsigned int a = 0x80000000;
  return (a & 0x80000000) ? 0x380000000LL : 0LL;
}

long long
f8 (void)
{
  printf("f8 ");
  unsigned int a = 0x80000000;
  return (a & 0x80000000) ? -2147483648LL : 0LL;
}

int
main (void)
{
  if ((char) 128 != -128 || (int) 0x80000000 != -2147483648)
    printf("return "); 		return 0; 
  if (f1 () != 128)
   { printf("abort_main "); 		abort (); }
  if (f2 () != 128)
   { printf("abort_main "); 		abort (); }
  if (f3 () != 896)
   { printf("abort_main "); 		abort (); }
  if (f4 () != -128)
   { printf("abort_main "); 		abort (); }
  if (f5 () != 0x80000000LL)
   { printf("abort_main "); 		abort (); }
  if (f6 () != 0x80000000LL)
   { printf("abort_main "); 		abort (); }
  if (f7 () != 0x380000000LL)
   { printf("abort_main "); 		abort (); }
  if (f8 () != -2147483648LL)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

