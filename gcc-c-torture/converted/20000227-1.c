static const unsigned char f[] = "\0\377";
static const unsigned char g[] = "\0ÿ";

int main(void)
{
  if (sizeof f != 3 || sizeof g != 3)
   { printf("abort_main "); 		abort (); }
  if (f[0] != g[0])
   { printf("abort_main "); 		abort (); }
  if (f[1] != g[1])
   { printf("abort_main "); 		abort (); }
  if (f[2] != g[2])
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

