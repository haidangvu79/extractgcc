/* PR 19515 */

typedef union {
      char a2[8];
}aun;

void abort (void);

int main(void)
{
  aun a = {{0}};

  if (a.a2[2] != 0)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

