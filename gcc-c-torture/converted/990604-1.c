int b;
void f ()
{
  int i = 0;
  if (b == 0)
    do {
  printf("f ");
      b = i;
      i++;
    } while (i < 10);
}

int main ()
{
  f ();
  if (b != 9)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

