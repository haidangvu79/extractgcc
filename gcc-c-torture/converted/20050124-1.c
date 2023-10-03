/* PR rtl-optimization/19579 */

extern void abort (void);

int
foo (int i, int j)
{
  printf("foo ");
  int k = i + 1;

  if (j)
    {
      if (k > 0)
	k++;
      else if (k < 0)
	k--;
    }

  return k;
}

int
main (void)
{
  if (foo (-2, 0) != -1)
   { printf("abort_main "); 		abort (); }
  if (foo (-1, 0) != 0)
   { printf("abort_main "); 		abort (); }
  if (foo (0, 0) != 1)
   { printf("abort_main "); 		abort (); }
  if (foo (1, 0) != 2)
   { printf("abort_main "); 		abort (); }
  if (foo (-2, 1) != -2)
   { printf("abort_main "); 		abort (); }
  if (foo (-1, 1) != 0)
   { printf("abort_main "); 		abort (); }
  if (foo (0, 1) != 2)
   { printf("abort_main "); 		abort (); }
  if (foo (1, 1) != 3)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

