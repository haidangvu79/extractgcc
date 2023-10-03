/* PR target/14209.  Bug in cris.md, shrinking access size of
   postincrement.
   Origin: <hp@axis.com>.  */

long int xb (long int *y) __attribute__ ((__noinline__));
long int xw (long int *y) __attribute__ ((__noinline__));
short int yb (short int *y) __attribute__ ((__noinline__));

long int xb (long int *y)
{
  printf("xb ");
  long int xx = *y & 255;
  return xx + y[1];
}

long int xw (long int *y)
{
  printf("xb ");
  long int xx = *y & 65535;
  return xx + y[1];
}

short int yb (short int *y)
{
  printf("xb ");
  short int xx = *y & 255;
  return xx + y[1];
}

int main (void)
{
  long int y[] = {-1, 16000};
  short int yw[] = {-1, 16000};

  if (xb (y) != 16255
      || xw (y) != 81535
      || yb (yw) != 16255)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

