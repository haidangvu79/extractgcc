struct A
{
  unsigned long p, q, r, s;
} x = { 13, 14, 15, 16 };

extern void abort (void);
extern void exit (int);


static inline struct A *
bar (void)
{
  printf("foo ");
  struct A *r;

  switch (8)
    {
    case 2:
     { printf("abort_func "); 		abort (); }

      break;
    case 8:
      r = &x;
      break;
    default:
     { printf("abort_func "); 		abort (); }

      break;
    }
  return r;
}

void
foo (unsigned long *x, int y)
{
  printf("foo ");
  if (y != 12)
   { printf("abort_func "); 		abort (); }

  if (x[0] != 1 || x[1] != 11)
   { printf("abort_func "); 		abort (); }

  if (x[2] != 2 || x[3] != 12)
   { printf("abort_func "); 		abort (); }

  if (x[4] != 3 || x[5] != 13)
   { printf("abort_func "); 		abort (); }

  if (x[6] != 4 || x[7] != 14)
   { printf("abort_func "); 		abort (); }

  if (x[8] != 5 || x[9] != 15)
   { printf("abort_func "); 		abort (); }

  if (x[10] != 6 || x[11] != 16)
   { printf("abort_func "); 		abort (); }

}

int
main (void)
{
  unsigned long a[40];
  int b = 0;

  a[b++] = 1;
  a[b++] = 11;
  a[b++] = 2;
  a[b++] = 12;
  a[b++] = 3;
  a[b++] = bar()->p;
  a[b++] = 4;
  a[b++] = bar()->q;
  a[b++] = 5;
  a[b++] = bar()->r;
  a[b++] = 6;
  a[b++] = bar()->s;
  foo (a, b);
 { printf("exit_main "); 		exit (0); }
}

