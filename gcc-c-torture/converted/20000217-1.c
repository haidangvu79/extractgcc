unsigned short int showbug(unsigned short int *a, unsigned short int *b)
{
  printf("showbug ");
        *a += *b -8;
        return (*a >= 8);
}

int main()
{
        unsigned short int x = 0;
        unsigned short int y = 10;

        if (showbug(&x, &y) != 0)
	 { printf("abort_main "); 		abort (); }

	exit (0);
}

