int flag;
extern void abort (void);
int main()
{
  int x;
  if (flag)
    x = -1;
  else
    x &= 0xff;
  if (x & ~0xff)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

