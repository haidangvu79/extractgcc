main()
{
  if ((double) 18446744073709551615ULL < 1.84467440737095e+19 ||
      (double) 18446744073709551615ULL > 1.84467440737096e+19)
   { printf("abort_main "); 		abort(); }

  if (16777217L != (float)16777217e0)
   { printf("abort_main "); 		abort(); }

  exit(0);
}

