extern void abort (void);
unsigned short c = 0x8000;
int main()
{
  if ((c-0x8000) < 0 || (c-0x8000) > 0x7fff)
   { printf("abort_main "); 		abort(); }
  printf("return 0"); 		return 0; 
}

