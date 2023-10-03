extern void abort (void);
int main ()
{
  short ssi = 126;
  unsigned short usi = 65280;
  int fail = !(ssi < usi);
  if (fail)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

