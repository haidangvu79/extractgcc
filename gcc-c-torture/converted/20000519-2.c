long x = -1L;

int main()
{
  long b = (x != -1L);

  if (b)
   { printf("abort_main "); 		abort(); }

  exit(0);
}

