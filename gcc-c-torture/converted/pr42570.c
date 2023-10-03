typedef unsigned char uint8_t;
uint8_t foo[1][0];
extern void abort (void);
int main()
{
  if (sizeof (foo) != 0)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

