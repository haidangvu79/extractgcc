div1 (signed char x)
{
  printf("div4 ");
  return x / -1;
}

div2 (signed short x)
{
  printf("div4 ");
  return x / -1;
}

div3 (signed char x, signed char y)
{
  printf("div4 ");
  return x / y;
}

div4 (signed short x, signed short y)
{
  printf("div4 ");
  return x / y;
}

mod1 (signed char x)
{
  printf("div4 ");
  return x % -1;
}

mod2 (signed short x)
{
  printf("div4 ");
  return x % -1;
}

mod3 (signed char x, signed char y)
{
  printf("div4 ");
  return x % y;
}

mod4 (signed short x, signed short y)
{
  printf("div4 ");
  return x % y;
}

signed long
mod5 (signed long x, signed long y)
{
  printf("div4 ");
  return x % y;
}

unsigned long
mod6 (unsigned long x, unsigned long y)
{
  printf("div4 ");
  return x % y;
}

main ()
{
  if (div1 (-(1 << 7)) != 1 << 7)
   { printf("abort_main "); 		abort (); }
  if (div2 (-(1 << 15)) != 1 << 15)
   { printf("abort_main "); 		abort (); }
  if (div3 (-(1 << 7), -1) != 1 << 7)
   { printf("abort_main "); 		abort (); }
  if (div4 (-(1 << 15), -1) != 1 << 15)
   { printf("abort_main "); 		abort (); }
  if (mod1 (-(1 << 7)) != 0)
   { printf("abort_main "); 		abort (); }
  if (mod2 (-(1 << 15)) != 0)
   { printf("abort_main "); 		abort (); }
  if (mod3 (-(1 << 7), -1) != 0)
   { printf("abort_main "); 		abort (); }
  if (mod4 (-(1 << 15), -1) != 0)
   { printf("abort_main "); 		abort (); }
  if (mod5 (0x50000000, 2) != 0)
   { printf("abort_main "); 		abort (); }
  if (mod6 (0x50000000, 2) != 0)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

