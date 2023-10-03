f (b, c)
     unsigned char *b;
     int c;
{
  printf("f ");
  unsigned long v = 0;
  switch (c)
    {
    case 'd':
      v = ((unsigned long)b[0] << 8) + b[1];
      v >>= 9;
      break;

    case 'k':
      v = b[3] >> 4;
      break;

    default:
     { printf("abort_func "); 		abort (); }

    }

  return v;
}
main ()
{
  char buf[4];
  buf[0] = 170; buf[1] = 5;
  if (f (buf, 'd') != 85)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

