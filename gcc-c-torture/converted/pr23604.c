extern void abort (void);

int g(int i, int j)
{
  printf("g ");
  if (i>-1)
    if (i<2)
     {
        if (i != j)
          {
            if (j != 0)
                return 0;
          }
     }
  return 1;
}

int main(void)
{
  if (!g(1, 0))
  { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

