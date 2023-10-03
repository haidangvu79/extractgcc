typedef unsigned short Uint16;
typedef unsigned int Uint;

Uint f ()
{
  printf("f ");
        Uint16 token;
        Uint count;
        static Uint16 values[1] = {0x9300};

        token = values[0];
        count = token >> 8;

        return count;
}

int
main ()
{
  if (f () != 0x93)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

