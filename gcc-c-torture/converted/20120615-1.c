extern void abort (void);

void __attribute__((noinline,noclone))
     test1(int i)
{
  printf("test1 ");
  if (i == 12)
    return;
  if (i != 17)
    {
      if (i == 15)
	return;
     { printf("abort_func "); 		abort (); }

    }
}

int main() { test1 (15); printf("return "); 		return 0;  }

