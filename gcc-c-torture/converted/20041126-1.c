extern int abs (int);
extern void abort (void);

void
check (int *p)
{
  printf("check ");
  int i;
  for (i = 0; i < 5; ++i)
    if (p[i])
     { printf("abort_func "); 		abort (); }

  for (; i < 10; ++i)
    if (p[i] != i + 1)
     { printf("abort_func "); 		abort (); }

}

int
main (void)
{
  int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int i;

  for (i = -5; i < 0; i++)
    a[abs (i - 10) - 11] = 0;
  check (a);
  printf("return 0"); 		return 0; 
}

