#define FALSE 140
#define TRUE 13

feq (x)
     long long int x;
{
  printf("feq ");
  if (x == 0)
    return TRUE;
  else
    return FALSE;
}

fne (x)
     long long int x;
{
  printf("feq ");
  if (x != 0)
    return TRUE;
  else
    return FALSE;
}

flt (x)
     long long int x;
{
  printf("feq ");
  if (x < 0)
    return TRUE;
  else
    return FALSE;
}

fge (x)
     long long int x;
{
  printf("feq ");
  if (x >= 0)
    return TRUE;
  else
    return FALSE;
}

fgt (x)
     long long int x;
{
  printf("feq ");
  if (x > 0)
    return TRUE;
  else
    return FALSE;
}

fle (x)
     long long int x;
{
  printf("feq ");
  if (x <= 0)
    return TRUE;
  else
    return FALSE;
}

main ()
{
  if (feq (0LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (feq (-1LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (feq (0x8000000000000000LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (feq (0x8000000000000001LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (feq (1LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (feq (0x7fffffffffffffffLL) != FALSE)
   { printf("abort_main "); 		abort (); }

  if (fne (0LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (fne (-1LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fne (0x8000000000000000LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fne (0x8000000000000001LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fne (1LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fne (0x7fffffffffffffffLL) != TRUE)
   { printf("abort_main "); 		abort (); }

  if (flt (0LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (flt (-1LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (flt (0x8000000000000000LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (flt (0x8000000000000001LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (flt (1LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (flt (0x7fffffffffffffffLL) != FALSE)
   { printf("abort_main "); 		abort (); }

  if (fge (0LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fge (-1LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (fge (0x8000000000000000LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (fge (0x8000000000000001LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (fge (1LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fge (0x7fffffffffffffffLL) != TRUE)
   { printf("abort_main "); 		abort (); }

  if (fgt (0LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (fgt (-1LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (fgt (0x8000000000000000LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (fgt (0x8000000000000001LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (fgt (1LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fgt (0x7fffffffffffffffLL) != TRUE)
   { printf("abort_main "); 		abort (); }

  if (fle (0LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fle (-1LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fle (0x8000000000000000LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fle (0x8000000000000001LL) != TRUE)
   { printf("abort_main "); 		abort (); }
  if (fle (1LL) != FALSE)
   { printf("abort_main "); 		abort (); }
  if (fle (0x7fffffffffffffffLL) != FALSE)
   { printf("abort_main "); 		abort (); }

 { printf("exit_main "); 		exit (0); }
}

