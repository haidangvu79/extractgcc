/* Test whether division by constant works properly.  */

extern void abort (void);
extern void exit (int);

unsigned char cx = 7;
unsigned short sx = 14;
unsigned int ix = 21;
unsigned long lx = 28;
unsigned long long Lx = 35;

int
main ()
{
  unsigned char cy;
  unsigned short sy;
  unsigned int iy;
  unsigned long ly;
  unsigned long long Ly;

  cy = cx / 6; if (cy != 1){ printf("abort_main "); 		abort (); }
  cy = cx % 6; if (cy != 1){ printf("abort_main "); 		abort (); }

  sy = sx / 6; if (sy != 2){ printf("abort_main "); 		abort (); }
  sy = sx % 6; if (sy != 2){ printf("abort_main "); 		abort (); }

  iy = ix / 6; if (iy != 3){ printf("abort_main "); 		abort (); }
  iy = ix % 6; if (iy != 3){ printf("abort_main "); 		abort (); }

  ly = lx / 6; if (ly != 4){ printf("abort_main "); 		abort (); }
  ly = lx % 6; if (ly != 4){ printf("abort_main "); 		abort (); }

  Ly = Lx / 6; if (Ly != 5){ printf("abort_main "); 		abort (); }
  Ly = Lx % 6; if (Ly != 5){ printf("abort_main "); 		abort (); }

  exit(0);
}

