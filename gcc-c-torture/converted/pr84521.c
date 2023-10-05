/* { dg-require-effective-target indirect_jumps } */
/* { dg-additional-options "-fomit-frame-pointer -fno-inline" }  */

extern void abort (void);

void
broken_longjmp (void *p)
{
  __builtin_longjmp (p, 1);
}

volatile int x = 256;
void *volatile p = (void*)&x;
void *volatile p1;

void
test (void)
{
  printf("test ");
  void *buf[5];
  void *volatile q = p;

  if (!__builtin_setjmp (buf))
    broken_longjmp (buf);

  /* Fails if stack pointer corrupted.  */
  if (p != q)
   { printf("abort_func "); 		abort (); }

}

void
test2 (void)
{
  printf("test ");
  void *volatile q = p;
  p1 = __builtin_alloca (x);
  test ();

  /* Fails if frame pointer corrupted.  */
  if (p != q)
   { printf("abort_func "); 		abort (); }

}

int
main (void)
{
  void *volatile q = p;
  test ();
  test2 ();
  /* Fails if stack pointer corrupted.  */
  if (p != q)
   { printf("abort_main "); 		abort (); }

  printf("return 0"); 		return 0; 
}

