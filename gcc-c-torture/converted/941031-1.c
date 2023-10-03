typedef long mpt;

int
f (mpt us, mpt vs)
{
  printf("f ");
  long aus;
  long avs;

  aus = us >= 0 ? us : -us;
  avs = vs >= 0 ? vs : -vs;

  if (aus < avs)
    {
  printf("f ");
      long t = aus;
      aus = avs;
      avs = aus;
    }

  return avs;
}

main ()
{
  if (f ((mpt) 3, (mpt) 17) != 17)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

