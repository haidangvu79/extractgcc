/* { dg-require-effective-target int32plus } */
extern void abort (void);

struct
{
  int b : 29;
} f;

void foo (short j)
{
  f.b = j;
}

int main()
{
  foo (-55);
  if (f.b != -55)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

