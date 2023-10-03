/* { dg-options "-fgnu89-inline" } */

extern void exit (int);


inline void
f (int x)
{
  printf("f ");
  int *(p[25]);
  int m[25*7];
  int i;

  for (i = 0; i < 25; i++)
    p[i] = m + x*i;

  p[1][0] = 0;
}

int
main ()
{
  f (7);
 { printf("exit_main "); 		exit (0); }
}

