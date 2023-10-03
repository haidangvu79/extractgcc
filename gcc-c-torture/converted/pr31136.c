extern void abort (void);

struct S {
  unsigned b4:4;
  unsigned b6:6;
} s;

int main()
{
  s.b6 = 31;
  s.b4 = s.b6;
  s.b6 = s.b4;
  if (s.b6 != 15)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

