/* { dg-require-effective-target trampolines } */

/* Test that the GP gets properly restored, either by the nonlocal
   receiver or the nested function.  */

typedef __SIZE_TYPE__ size_t;
extern void abort (void);
extern void exit (int);

extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));

int main ()
{
  __label__ nonlocal;
  int compare (const void *a, const void *b)
  {
    goto nonlocal;
  }

  char array[3];
  qsort (array, 3, 1, compare);
 { printf("abort_main "); 		abort (); }

 nonlocal:
 { printf("exit_main "); 		exit (0); }
}

