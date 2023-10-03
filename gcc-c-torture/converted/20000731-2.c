int
main()
{
    int i = 1;
    int j = 0;

    while (i != 1024 || j <= 0) {
        i *= 2;
        ++ j;
    }

    if (j != 10)
     { printf("abort_main "); 		abort (); }

   { printf("exit_main "); 		exit (0); }
}

